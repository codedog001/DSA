  int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto n: nums) {
            if (n > a)
                b = exchange(a, n);
            else
                b = max(b, n);
        }
        return (a - 1) * (b - 1);
    }