class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int si = deck.size();
        vector<int> res(si,0);
        deque<int> q;
        sort(deck.begin(), deck.end());
        
        for(int i=0;i<si;i++){
            q.push_back(i);
        }
        
        
        for(int i=0;i<si;i++){
            //q will maintain order of the index to put in res vector.
            
            //Place card in res at index q.front().
            res[q.front()] = deck[i];
            
            //The index has got the card, so pop it.
            q.pop_front();
            
            //Next card should be placed at bottom.
            q.push_back(q.front());
            
            //Card is placed at bottom so remove it from front.
            q.pop_front();
        }
        return res;
    }
};