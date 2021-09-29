int maxVowels(string s, int k) {
        int i=0,j=0,count=0,maxVow=0;
        while(j<s.size()){
            //1. Calculation
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') count++;
            
            if(j-i+1 < k) j++;
            
            //When k size is reached
            else if(j-i+1 == k){
                //i. Get answer from calculation
                maxVow = max(count,maxVow);
                //Remove i from calculation
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count--;
                
                //iii. Slide window
                i++;
                j++;
            }
        }
        return maxVow;
    }