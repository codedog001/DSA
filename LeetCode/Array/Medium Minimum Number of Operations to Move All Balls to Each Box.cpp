class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ballCount = 0;
        vector<int> res(boxes.size(),0);
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        if(boxes[0] == '1'){
            ballCount+=1;
        }
        //i=1 because left[0] will always be 0, because there is no ball before index 0.
        for(int i=1;i<n;i++){
            left[i] = ballCount + left[i-1];
            if(boxes[i] == '1'){
                ballCount += 1;
            }
            
        }
        
        if(boxes[n-1] == '1'){
            ballCount=1;
        }else{
            ballCount = 0;
        }
        
        //i=n-2 because right[n-1] will always be 0, because there is no ball after last box.
        for(int i=n-2;i>=0;i--){
            right[i] = ballCount + right[i+1];
            if(boxes[i] == '1'){
                ballCount += 1;
            }
            
        }
        
        
        
        //Result is sum of left and right
        for(int i=0; i<res.size(); i++){
            res[i] = left[i] + right[i];
        }
        
        return res;
    }
};