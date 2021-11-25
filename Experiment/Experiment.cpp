//Aim is to show unordered map stores most recent key value pair. 
// Output shows 'b' key mapped with value 6, while 'b' first entered at c=2.
//Problem URL: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

unordered_map<char, int> x;
        string s= "abbbcb";
        int c=1;
        for(auto &g:s){
            x[g] = c;
            cout << "PAIR: " << g << " & " <<c << endl;
            c++;
        }
        for(auto &g:s){
            cout << "MAP HAS: " << g << " VAL: " << x[g] << endl;
        }
        cout << "RESULT: " << x['b'] << endl;
