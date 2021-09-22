bool containsNearbyDuplicate(vector<int>& a, int k) {
        unordered_set<int> m;
        for (int i = 0; i < a.size(); i++) {
            if (i > k) {
                m.erase(a[i - k - 1]);
            }
            if (!m.insert(a[i]).second) {
                return true;
            }
        }
        return false;
    
    }