int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    string a;
	    cin >> a;
	    bool z=false, o=true;
	    int count = 0;
	    for(auto &c:a){
	        if(c=='0'){
	            if(z==true) continue;
	            else if(z==false){
	                count++;
	                z=true;
	                o=false;
	            }
	        }
	        else if(c=='1'){
	            if(o==true) continue;
	            else if(o==false){
	                count++;
	                o=true;
	                z=false;
	            }
	        }
	    }
	    cout << count << endl;
	}
}