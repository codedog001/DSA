#include<unordered_map>
int highestFrequency(int arr[], int n) {
    
    // Write your code here
    int maxFreq=0;
    int maxFreqEle = 0;
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }
    for(int i=0; i<n; i++){
        if(m[arr[i]] == maxFreq) return arr[i];
    }
    return 0;
}