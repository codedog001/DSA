class Solution {
public:
    
    void flip(vector<int> &a, int index){
        for(int i=0,j=index;i<=index/2;i++,j--){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        return;
    }
    
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> result;
        for(int i=a.size()-1;i>0;i--){
            for(int j=1;j<=i;j++){
                if(a[j] == i+1){
                    flip(a,j);
                    result.push_back(j+1);
                }
            }
            flip(a,i);
            result.push_back(i+1);
        }
        return result;
    }
};