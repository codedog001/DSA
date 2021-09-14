//There is nothing to do in induction step.
	int func(int k, vector<int> v, int index){
		//Base Case
        if(v.size()==1){
            return v[0];
        }
        
        //Hypothesis
        index = (index + k) % v.size();
        v.erase(v.begin() + index);
        return func(k,v,index);
    }
    int findTheWinner(int n, int k) {
        vector<int> v(n,0);
        for(int i=1; i<=n; i++){
            v[i-1] = i;
        }
        
        //Index is the index of person who dies
        int index=0;
        //We change k to k-1. For e.g: If k=3 person 1 kills 3, person at index 0 will kill the one at index 2
        int res = func(k-1,v,index);
        return res;
    }