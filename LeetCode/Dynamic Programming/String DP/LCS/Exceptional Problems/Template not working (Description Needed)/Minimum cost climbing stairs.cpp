//What didn't work:
1. Array of size of n+1 is giving error in bottom up.
2. If array is of size n+1, loop will also go till n+1, and it will be cost[i-1] instead of cost[i] in the loop, but using cost[i-1] in that case is also giving error.
3. It contradicts with, array of size n+1 is needed to get the answer, array of size n is giving right answer is fine, but array of size n+1 should also give right answer.
4. Array of size n+1 is working with memoization, not with bottom up.

1. Memoization (Top Down)

int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int t[n];
        for(int i=0; i<n; i++) t[i] = -1;
		
		//Hypothesis of my function fun(n) is, when I call it, it will return the cost of climbing n steps. What I want is minimum cost of climbing 1 steps at a time or 2 steps at a time.
		//Therefore min(fun(n-1), fun(n-2)) is called.
        return min(fun(cost, n-1, t), fun(cost, n-2, t));
    }
    
    int fun(vector<int>& cost, int n, int* t){
        //Base Case
        if(n<0)return 0;
        if(n==0 || n==1 ) return cost[n];
        
        //Check if answer already exists
        if(t[n] != -1) return t[n];
        
        //Store answer and also the induction step.
		//When we move forward from current step, the cost of current step cost[n] is added, the total cost becomes: 
		// Cost of current step + (as explained earlier) minimum cost of climbing 1 or 2 steps  at a time.
        t[n] = cost[n] + min(fun(cost, n-1, t), fun(cost, n-2, t));
        
        //Return answer
        return t[n];
    }
2. DP (Bottom Up)

      int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int t[n];
        
        //Initialization
        t[0] = cost[0];
        t[1] = cost[1];
        
        //Knapsack 01
        for(int i=2; i<n; i++){
            t[i] = cost[i] + min(t[i-1], t[i-2]);
        }
        //Return answer
        return min(t[n-1], t[n-2]);
    }