	int search(string pat, string a) {
	    // code here
	    int i=0,j=0,count=0,ans=0;
	    int k= pat.size();
	    int n = a.size();
	    unordered_map<char,int> m;
	    
	    for(auto &c:pat) m[c]++;

	    count = m.size();
	    while(j<n){
	        if(m.find(a[j]) != m.end()){ 
	            m[a[j]]--;
	            if(m[a[j]] == 0) count--;
	        }

	        if(j-i+1 <k)j++;
	        
	        else if(j-i+1 ==k){
	            //Get ans from calculation
	            if(count==0) ans+=1;
	            
	            //Remove i from calculation
	            if(m.find(a[i]) != m.end()){
	                m[a[i]]++;
	                if(m[a[i]] == 1) count+=1;
	            } 
	            
	            
	            //Slide Window
	            i++;
	            j++;
	            
	        }
	        
	    }
	    return ans;
	    
	}