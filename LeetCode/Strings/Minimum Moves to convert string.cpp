    int minimumMoves(string a) {
        int i=0,count = 0;

        for(i=0; i<a.size();i++){
            if(a[i] == 'O') continue;
            if(a[i]=='X'){
                count++;
                i+=2;
            }
        }
        return count;
    }