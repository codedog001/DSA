// Q: FIND DUPLICATE ELEMENT IN ARRAY OF SIZE N+1

int findDuplicate(vector<int>& a) {
	//Using the LL cycle approach
	int fast =a[0], slow =a[0];

	//Move fast by 2 and slow by 1 until they meet.
	do{
		slow = a[slow];
		fast = a[a[fast]];
	}while(slow!=fast);

	//When they meet assign fast to start and move both one step at a time, the point where they meet is the duplicate element.
	fast = a[0];
	while(slow!=fast){
		slow = a[slow];
		fast = a[fast];
	}
	return slow;
}