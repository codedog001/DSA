int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto &c: operations){
            if(c=="X++" || c=="++X") x+=1;
            else x-=1;
        }
        return x;
    }