void merge(long long one[], long long two[], int sizeOne, int sizeTwo) {
        int i=sizeOne-1, j = 0;
        //GOD LEVEL LOGIC: Start swapping elements from end or arr1 and start of arr2, this way largest elements of arr1 will get replaced by smallest elements of arr2.
        while(i>=0 and j<sizeTwo){
            if(one[i]>two[j])
                swap(one[i],two[j]);
            i--,j++;
        }
        sort(one,one+sizeOne);
        sort(two,two+sizeTwo);
	}
