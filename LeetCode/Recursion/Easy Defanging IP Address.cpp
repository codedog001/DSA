void rec(string& a, int index){
        if(index == a.size()) return;
        rec(a,index+1);
        if(a[index] == '.'){
            int n = a.size();
            a.resize(a.size()+2); //'.' becomes '[.]' so we need 2 extra space.
            for(int i=n-1;i>=index+1;i--) a[i+2] = a[i]; //Shift elements to 2 right spaces
            a[index+0] = '[';
            a[index+1] = '.';
            a[index+2] = ']'; 
        }
        return;
    }
    string defangIPaddr(string address) {
        rec(address, 0);
        return address;
    }