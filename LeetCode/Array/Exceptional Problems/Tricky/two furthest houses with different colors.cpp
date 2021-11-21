class Solution {
public:
    int maxDistance(vector<int>& a) {
        int difColor = INT_MAX, res = 1;

        for (int i = 1; i < a.size(); ++i) {
            if (a[i] != a[0]) difColor = min(difColor, i);
            res = max({res, a[i] == a[0] ? 0 : i, i - difColor });
        }
        return res;
    }
};