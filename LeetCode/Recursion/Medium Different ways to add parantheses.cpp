vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        cout << strlen(s.c_str()) << endl;
        for(int i=0; i<s.size(); i++){ //Let string be: "2*3-4*5"
            char c= s[i];
            if(c=='-' || c=='+' || c=='*'){
                string a = s.substr(0,i); //a: 2
                string b = s.substr(i+1); //b: 3-4*5
                
                //Hypothesis
                vector<int> a1 = diffWaysToCompute(a);
                vector<int> b1 = diffWaysToCompute(b);
                
                //Induction: Perform arithmetic operation: (2) * (3-4*5) and store it in result
                for(int x:a1){
                    for(int y:b1){
                        if(c=='-'){
                            res.push_back(x-y);
                        }else if(c=='*'){
                            res.push_back(x*y);
                        }else if(c=='+'){
                            res.push_back(x+y);
                        }
                    }
                }
            }
        }
        // if the input string contains only number
        if (res.empty()) res.push_back(atoi(s.c_str()));
        return res;
    }