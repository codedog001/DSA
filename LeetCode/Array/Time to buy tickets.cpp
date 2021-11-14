0. Optimal
int timeRequiredToBuy(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += min(A[k] - (i > k), A[i]);
        }
        return ans;
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

