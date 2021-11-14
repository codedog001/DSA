0. Optimal
For an optimized approach :

Add min(tickets[i],tickets[k]) upto k (inclusive).
Add min(tickets[i],tickets[k] - 1) after k.
Return the count.
Time : O(n) , Space : O(1)

class Solution {
    public int timeRequiredToBuy(vector<int> tickets, int k) {
        int res = 0;
        for(int i = 0;i<tickets.size();i++){
            if(i <= k){
                res += min(tickets[k],tickets[i]);
            }else{
                res += min(tickets[k] - 1,tickets[i]);
            }
        }
        return res;
    }
}


1. Brute Force
int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        while(tickets[k] != 0){
            for(int i=0; i<tickets.size(); i++){
                if(tickets[i] > 0){
                    tickets[i] -= 1;
                    res += 1;
                }
                if(tickets[k] == 0) break;
            }
        }
        return res;
    }

