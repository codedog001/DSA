//To be solved in O(n) T.C.
// P.S: You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// Sample Output 1 :
// 8 12 

#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, pair<int,bool>> m;
    for(int i=0; i<n;i++) m[arr[i]] = {i, false};
    
    int start = -1, end = -1, len =0, maxLen = 0,temp = start, startIndex = 0;
    vector<int> res(3,0);
    
    for(int i=0; i<n; i++){
        temp = arr[i];
        
        //If this element has already been visited then skip it.
        if(m[temp].second == true) continue;
        len = 0;
        
        //Find consecutive greater elements than current element
        while(m.find(temp) != m.end()) {
            len++;
            end = temp;
            m[temp].second = true;
            ++temp;
        }
        
        temp = arr[i];

        //Find consecutive smaller elements than current element
        while(m.find(temp) != m.end()){
            start = temp;
            startIndex = m[temp].first;
            len++;
            m[temp].second = true;
            --temp;
        }
	
        
        if(len > maxLen || (len == maxLen && startIndex < res[2])){
            maxLen = len;
            res[0] = start;
            res[1] = end;
            res[2] = startIndex;
        }
    }
    res.pop_back();
    if(res[0] == res[1]) return {res[0]};
    return res;
}