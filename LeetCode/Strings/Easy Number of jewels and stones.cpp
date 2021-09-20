3. Using hashset
T.C: O(M+N)
S.C: O(M), where M is number of jewels.

int numJewelsInStones(string jewel, string stones) {
        int res = 0;
        unordered_set<char> map(jewel.begin(), jewel.end());
        for (char s : stones)
            if (map.find(s) != map.end()) res++;
        return res;
    }

1. For each char of stones, go through each char of jewels, break loop when found.
T.C: O(M * N)

    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(auto &c:stones){
            for(auto &d:jewels){
                if(c == d) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
2. For each char of jewels, count how many jewels are in stones.
T.C: O(M * N)

int numJewelsInStones(string jewels, string stones) {
    int num = 0;
    for (int i = 0; i < jewels.size(); i++){
        num += count(stones.begin(), stones.end(), jewels[i]);
    }
    return num;
}
