int maximumUniqueSubarray(vector<int>& a) {
     int i=0,j=0,maxSum=0,sum=0;
     unordered_map<int,int> m;
     int count = 0; // Count stores no. of unique elements.
     for(j=0; j<a.size(); j++){
         sum += a[j];
         m[a[j]]++;
         if(m[a[j]] == 1) count++;
         
         //Duplicate element has entered the window
         if(j-i+1 > count){
             while(j-i+1>count){
                 sum -= a[i];
                 m[a[i]]--;
                 if(m[a[i]] == 0) count--;
                 i++;
             }
         }
         maxSum = max(maxSum, sum);
         
     }
     return maxSum;
 }