/////////////
/////////////////
////////////////////////
////////////////////////////////

// VECTOR APPROACH

////////////////////////////////
///////////////////
////////////////
///////////





class BrowserHistory {
public:
    vector<string> v;
    int pos;
    
    BrowserHistory(string homepage){
        v.push_back(homepage);
        pos = 0;
    }
    
    void visit(string url){
        pos++;
        v.resize(pos);
        v.push_back(url);
    }
    
    string back(int steps){
        pos = max(0,pos-steps);
        return v[pos];
    }
    
    string forward(int steps){
        pos = min((int)v.size()-1,pos+steps);
        return v[pos];
    }
};