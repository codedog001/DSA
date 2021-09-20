int function(vector<int> &a, int target){
    map<int,int> map;
    int count = 0;
    int xorRes = 0;

    for(auto &g: a){
        xorRes = xorRes ^ g;
        if(xorRes == target) count++;
        if(map.find(xorRes ^ target) != map.end()) count += map[xorRes ^ target];
        map[xorRes] += 1;
    }
    return count;
}