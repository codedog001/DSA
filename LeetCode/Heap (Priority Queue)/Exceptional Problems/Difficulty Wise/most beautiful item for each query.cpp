// Code had bugs during contest but I'm glad that it later worked. and I'm very glad that I was able to do it somehow.
// Please dry run the solution atleast once, it is very simple, much simpler than what it looks.

// Logic: On top of max heap we store max weight.
// Then, we sort queries[], and start traversing from maximum price, if we can't afford what is at the top of heap, we pop out until we reach a price which we can afford. I have commented this part in code.
// How to check what we can afford, map will do that for us: {weight: price}.

// Since we sorted queries[], we need to put elements back at their right position, copy[] array does that, it stores initiial queries, and later we fetch the corresponding {price: weight} pair from sorted map and store it at correct location in res.

// T.C: Mainly due to following operations - Inserting all weight into heap O(MlogM) + sorting the queries[] array O(NlogN) = O(NlogN) + O(MlogM)
// where M = items.size(), N = queries.size()


vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> m;
        priority_queue<int> maxHeap;
        for(auto &c:items){
            int price = c[0], wt = c[1];
            maxHeap.push(wt);
            if(m.find(wt) != m.end()) {
                if(m[wt] > price) m[wt] = price;
            }
            else m[wt] = price;
        }
       
        vector<int> copy(queries.size(), 0);
        for(int i=0; i<queries.size(); i++) copy[i] = queries[i];
        sort(queries.begin(), queries.end());
        
        unordered_map<int, int> sorted;
        
        for(int i=queries.size()-1; i>=0; i--){
            int c = queries[i];
			// We can afford this
            if(m[maxHeap.top()] <= c) sorted[c] = maxHeap.top();
            else{
			//We can't afford what is at top currently. So, pop until we reach a weight that we can afford. 
                while(maxHeap.size() && m[maxHeap.top()] > c) maxHeap.pop();
                if(maxHeap.size()) sorted[c] = maxHeap.top();
            }
        }
        vector<int> res(queries.size(), 0);
		//Insert elements at right place as per queries[]
        for(int i=0; i<copy.size(); i++) res[i] = sorted[copy[i]];
        
        return res;
    }