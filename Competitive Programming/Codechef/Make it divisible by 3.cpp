int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int digits;
	    cin >> digits;
	    cout << "3";
	    for(int i=0; i<digits-2; i++) cout << "0";
	    if(digits != 1)cout << "3";
	    cout << endl;
	}
}