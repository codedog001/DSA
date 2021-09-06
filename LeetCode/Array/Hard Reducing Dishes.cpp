class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size();
        // for(auto &g:s){
        //     cout << g << " ";
        // }
        
        //We also include negative elements because they increase multiplying factor.
        cout << endl;
        int total = 0;
        int start = n-1;
        for(int i=n-1; i>=0;i--){
            total += s[i];
            
            //If element in array is making the total below 0, it is harming rather than benifiting.
            if(total < 0){
                break;
            }
            start--;
        }
        //Moving start ahead by 1 step, because last added value made total < 0 or made it -1.
        start++;
        // cout << "S: "<< start << endl;
        total = 0;
        int k =1;
        for(int i= start; i<n; i++){
            total += (k++)*s[i];
        }
        return total;
    }
};