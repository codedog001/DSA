1. No heap/sorting - O(n) time, O(1) space

#define ll long long
class Solution {
public:
    int thirdMax(vector<int>& a) {
        ll fm, sm, tm, n = a.size();
        fm = sm = tm = LLONG_MIN;
        
        for(int i=0; i<n; i++){
            if(a[i] <= tm) continue;
            else if(a[i] > fm){
                tm = sm;
                sm = fm;
                fm = a[i];
            }
            else if(a[i] > sm && a[i] < fm){
                tm = sm;
                sm = a[i];
            }
            else if(a[i] > tm && a[i] < sm){
                tm = a[i];
            }
        }
        return tm == LLONG_MIN ? fm : tm;
    }
};
2. Using Heap and Set

class Solution {
public:
    int thirdMax(vector<int>& a) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> s;
        int maxi = a[0];
        for(int i=0; i<a.size(); i++){
            if(s.find(a[i]) == s.end()) {
                minHeap.push(a[i]);
                s.insert(a[i]);
                if(a[i] > maxi) maxi = a[i];
            }
            if(minHeap.size() > 3) minHeap.pop();
        }
        return minHeap.size() == 3 ? minHeap.top() : maxi;
    }
};