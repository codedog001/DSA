Not a hard problem if you know heaps. All you need is, push every node value into min heap.

T.C: O(nmlog(nm))
S.C: O(n*m)
where n: Maximum no. of lists
m: Maximum no. of nodes in list

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        if(l.empty()) return NULL;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<l.size(); i++){
            
            auto head=l[i];
            while(head){
                minHeap.push(head->val);
                head = head -> next;
            }
            
        }
        auto temp = new ListNode(0);
        auto tail = temp;
        while(!minHeap.empty()){
            auto n = new ListNode(minHeap.top());
            tail -> next = n;
            tail = tail -> next;
            minHeap.pop();
        }
        tail -> next = NULL;
        return temp -> next;
    }