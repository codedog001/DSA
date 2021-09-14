string rec(string s,int& pos){
	int repeat = 0;   
	string finalRes = "";
	for(;pos<s.size();pos++){
		char cur = s[pos];
		if(cur == '['){
			string smallResult = rec(s,++pos);
			for(;repeat>0;repeat--) finalRes += smallResult;
		}
		//In case of no.
		else if(cur>='0' && cur <='9') repeat = repeat*10 +cur - '0';
		
		//When bracket ends
		else if(cur == ']') return finalRes;
		
		//For words without repeating no.
		else finalRes += cur;
	}
	return finalRes;
}

string decodeString(string s) {
 int pos = 0;
	return rec(s,pos);
}