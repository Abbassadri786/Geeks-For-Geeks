// Approach: DP Memoization Take or ot take approach
class Solution {
    
    int dp[1001][1001];   // memo table
    
private:
    int helper(int W, vector<int> &wt, vector<int> &val, int n){
        
        // Base case
        if(n == 0 || W == 0){
            return 0;
        }
        
        // Check memo table
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        
        // If weight can be included
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + helper(W - wt[n-1], wt, val, n-1), helper(W, wt, val, n-1));
        }
        
        // If weight cannot be included
        else{
            return dp[n][W] = helper(W, wt, val, n-1);
        }
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        memset(dp, -1, sizeof(dp));  // initialize DP
        
        int n = wt.size();
        
        return helper(W, wt, val, n);
    }
};
