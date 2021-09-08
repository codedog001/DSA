class Solution {
public:
    int findLen(ListNode * head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* p = NULL;
        if(head == NULL){
            while(k!=0){
                res.push_back(head);
                k--;
            }
            return res;
        }
        if(head -> next == NULL){
            k--;
            res.push_back(head);
            while(k!=0){
                res.push_back(p);
                k--;
            }
            return res;
        }
        
        int len = findLen(head);
        if(len <= k){
            ListNode* temp = head;
            while(temp != NULL && k!=0){
                res.push_back(temp);
                ListNode * n = temp-> next;
                temp -> next = NULL;
                temp = n;
                k--;
            }
            while(k!=0){
                res.push_back(p);
                k--;
            }
            return res;
        }
        else if(len>k){
            int allParts = len / k;
            int extraLen = len % k;
            
            ListNode *temp = head;
            int remLen = len;
            
            while(temp!=NULL){
                
                //Uniformly add extraLen to all the linked list.
                int t2 = allParts;
                if(extraLen > 0 && k> 0 && extraLen/k == 0){
                    t2+= 1;
                }
                
                //If remaining length is less than t2, create LL of remLen instead of t2.
                int t = remLen>=t2 ? t2 :remLen;
                cout << "ALL " << t2 << endl;
                ListNode * smallHead = temp;
            
                while(t>1){
                    temp = temp->next;
                    t--;
                }
                ListNode* n1 = NULL;
                if(temp->next){
                    
                   n1 = temp -> next;
                }else{
                    n1= NULL;
                }
                temp -> next = NULL;
                res.push_back(smallHead);
                temp = n1;
                remLen-=t2;
                k--;
                extraLen--;
            }
            return res;
            
        }
        
        return res;
    }