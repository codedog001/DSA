1. Single Pass
T.C: O(n)
S.C: O(1)

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head) return {-1,-1};
        int first = INT_MAX, last=0, prev = head -> val, mini=INT_MAX;
        for(int i=0; head->next; ++i){
            if((head->val > prev && head->val > head->next->val) || (prev > head->val && head->val < head->next->val)){
                if(last!=0) mini = min(mini, i-last);
                last = max(last, i);
                first = min(first, i);
            }
            prev = head->val;
            head = head->next;
        }
        if(mini == INT_MAX) return {-1,-1};
        return {mini, last-first};
    }
};
2. Using max heap
T.C: O(nlogn)
S.C: O(n)

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next) return {-1,-1};
        ListNode *prev = NULL, *cur = head, *n = cur->next;
        priority_queue<int> criticalIndex;
        int i=0;
        
        //Store index of all critical points in the max heap.
        while(n){
            if(prev && n && cur){
			//Local maxima
                if(cur-> val > n-> val && cur-> val > prev->val) criticalIndex.push(i+1);
			//Local minima
                else if(cur->val < n->val && cur->val < prev->val) criticalIndex.push(i+1);
            }
		//Move pointers
            prev = cur;
            cur = n;
            n = cur->next;
            i++;
        }
        
        if(criticalIndex.size() < 2) return {-1, -1};
        
        //Find minimum and maximum distance.
        //Maximum distance => largest element (top of max heap) - smallest element (last element of max heap)
        //Minimum distance => It follows no strict formula, difference of any 2 distance can be minimum, so it will be calculated through the loop.
        
        int minDif = INT_MAX, maxDif = criticalIndex.top(), lastEle = criticalIndex.top(), first = 0; //first will store last element of max heap.
        
        criticalIndex.pop();
        if(criticalIndex.size() == 1) first = criticalIndex.top();
        
        while(!criticalIndex.empty()){
            minDif = min(minDif, abs(lastEle-criticalIndex.top()));
            lastEle = criticalIndex.top();
            criticalIndex.pop();
            if(criticalIndex.size() == 1) first = criticalIndex.top();
        }
        
        maxDif = maxDif - first;
        return {abs(minDif), abs(maxDif)};
    }
};