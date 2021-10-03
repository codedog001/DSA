   int maxFrequency(vector<int> A, int k) {
        int res = 1, i = 0, j;
        long sum = 0;
        sort(A.begin(), A.end());
        for (j = 0; j < A.size(); ++j) {
            sum += A[j];
            while (sum + k < (long)A[j] * (j - i + 1)) {
                sum -= A[i];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }