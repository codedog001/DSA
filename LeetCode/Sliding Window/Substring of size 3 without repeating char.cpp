//LEETCODE

int countGoodSubstrings(string s) {
        int i=0,j=0,count=0;
        deque<char> d;
        while(j<s.size()){
            //1.Calculation
            d.push_back(s[j]);
            
            //2. Move j
            if(j-i+1 < 3) j++;
            
            //3. When window size is reached
            else if(j-i+1==3){
                
                //1. Get Answer from calculation
                bool dup = false;
                for(int i=0;i<d.size(); i++){
                    for(int j=i+1; j<d.size()-i+1; j++){
                        if(d[i] == d[j]){
                            dup = true;
                            break;
                        }
                    }
                }
                if(dup==false) count++;
                
                //ii. Remove i from calculation
                d.pop_front();
                
                //iii. Slide Window
                i++;
                j++;
            }
        }
        return count;
    }