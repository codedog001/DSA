string freqAlphabets(string s) {
    string res = "";
	
	//E.g: "10#11#12"
    for(int i=s.size()-1; i>=0;i--){
        if(s[i] == '#'){ 
		
		//10#
            int num1 = (int)s[i-2] - 48;  //num 1 = 1 (Logic of ((int) s[i-1] - 48) expalined in else case.)
            int resNum = num1 *10 + ((int)s[i-1] - 48); //1*10 + ((int) s[i-1] - 48)= 10 + 0 
            res.push_back((char)resNum + 96);
            i-=2;
        }else{
		
		//2 -> b 
            int num1 = (int)s[i] - 48; //s[i] == '2' ('2' is char) -> (int) s[i] = 50 (ASCII value of '2' is 50)-> 50-48 == 2 -> num 1 == 2.
            res.push_back((char)num1 + 96); // (char) 2+96 = 98 (ASCII of b) -> b
        }
    }
     reverse(res.begin(), res.end()); //We started from end by pushing characters, now reverse res string.
    return res;
}