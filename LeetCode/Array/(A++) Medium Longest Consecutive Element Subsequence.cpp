1. Using Sorting

int longestConsecutive(vector<int>& a) {
        if(a.empty()) return 0;
        sort(a.begin(), a.end());
        int maxLen = 0, consecCount = 0;
        
        //Keep the maximum running consecutive count in maxLen and current consecutive count in consecCount -> maxLen will be the larger one.
        
        for(int i=0; i<a.size()-1; i++){
            if(a[i] == a[i+1]) continue; //It handles the case like 0,1,1,2 (Give it a dry run)
            if(a[i+1] - a[i] == 1){
                consecCount+=1;
                maxLen = max(maxLen, consecCount);
            }
            else consecCount = 0;
        }
        return maxLen+1;
    }
T.C- O(nlogn) (sorting) + O(n) (iterating through array)
S.C - O(1), unless merge sort is used, in case of merge sort - O(n)

2. Using hashset

int longestConsecutive(vector<int>& a) {
        if(a.empty()) return 0;
        unordered_set<int> m;
        int maxLen = 0;
        //1. Insert all elements into the hashset.
        for(int num:a){ 
            m.insert(num);
        }
        
        //2. Search in array a, whether a[i]-1 exists in the hashset
        for(int num:a){
            
            if(m.find(num-1) == m.end()){
                int curNum = num;
                int count = 1;
				
				//Part A - Refer Time Complexity
                while(m.find(curNum+1) != m.end()){ 
                    curNum+=1;
                    count+=1;
                }
                maxLen = max(count, maxLen);
            }
        }
        return maxLen;
    }
T.C- O(n) (inserting elements into hashset) + O(n) (iterating through array) + O(n) (Part A)
S.C - O(1)

Something I'm not able to understand- First solution does a great job if results from OJ are considered, while second barely misses TLE. If you know why, kindly share in comments.