#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int ma) {
    // Write your code here.
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr1[i]]++;
    }
    for(int i=0; i<ma; i++){
        if(m.count(arr2[i])> 0) {
            cout << arr2[i] << endl;
            m[arr2[i]]--;
            if(m[arr2[i]] == 0) m.erase(arr2[i]);
        }
    }
}