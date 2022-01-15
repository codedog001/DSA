int Solution::solve(vector<int> &a, int b) {
    int cpx = 0, count = 0, n = a.size();
    unordered_map<int, int> m;

    for(int i=0; i<n; i++) {
        cpx = cpx ^ a[i];
        if(cpx == b) count++;
        
        int y = cpx ^ b;
        if(m.find(y) != m.end()) count += m[y];

        m[cpx] += 1;
    }

    return count;
}
