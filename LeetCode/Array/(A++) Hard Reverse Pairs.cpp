int count;
    void merge(vector<int>& a, int start, int mid, int end){
        int left = start;
        int right = mid+1;
        //The most crucial part where count changes.
        
        //Similar to inversion count (link at the end).
        //Left: 25, 40
        //Right: 12, 19, 30
        //Pointer is on 25 and 12
        // 25 > 12*2 -> count = mid - left + 1 = 2 and right++
        // 25 < 19*2 -> left++, pointer is on 40 and 19
        // 40 > 19*2 -> count =  mid - left + 1 + 2 (previous count) = 3
        //Terminates.
        
        while(left<=mid && right<=end){
            if((long)a[left] > (long)2*a[right]){
                count += (mid - left + 1);
                right++;
            }else{
                left++;
            }
        }
        
        //Now we need to merge like the normal merge sort or let sort() handle it.
        sort(a.begin()+start, a.begin()+end+1);
        return;
    }
    void mergeSort(vector<int>& a, int start, int end){
        if(start == end) return;
        
        int mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,mid,end);
        return;
    }
    int reversePairs(vector<int>& nums) {
        if(!nums.size()) return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }