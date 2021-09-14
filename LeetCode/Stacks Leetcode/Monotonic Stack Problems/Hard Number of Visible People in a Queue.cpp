class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        //Using Monotonic Stack
        vector<int> monoStack;
        for(int i=heights.size()-1; i>=0; i--){
            int personHeight = heights[i];
            int smallPersonCanSee = 0;
            
            //No. of elements this person can pop are the no. of small height person it can see.
            while(monoStack.size()>0 && monoStack.back()<personHeight){
                monoStack.pop_back();
                smallPersonCanSee++;
            }
            
            //If there is some element in stack, that means current person can see 1 more person than 
            //they popped out. 
            
            //Eg: if there are 6,8 and 11 in stack and 10 is current person's height
            //10 can pop out 6 and 8 -> smallPersonCanSee = 2
            //But 11 will still be there, so 10 can see total 3
            
            //if(stack.size()>0) => add 1 to smallPersonCanSee
            
            int totalPersonCanSee = smallPersonCanSee + !monoStack.empty();
            heights[i] = totalPersonCanSee;
            
            monoStack.push_back(personHeight);
            
        }
        
        return heights;
    }
};