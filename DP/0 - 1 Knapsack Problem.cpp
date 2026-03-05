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



class Solution {
    // Approach 2:  Using Top Down matrix
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        int dp[n+1][W+1];
        // Step 1: Initialize matrix using recurssive base conditon
        for(int i=0; i < n + 1; i++){
            for(int j=0; j < W + 1; j++){
                if( i == 0 || j ==0){
                    dp[i][j] = 0;
                }
            }
        }
        
        //Step 2: Iterative solution traverse through matrix and replace n -> i and W -> j of memo sol
        // Fill up the Dp Table
        for(int i = 1; i< n + 1; i++){
            for(int j = 1; j< W + 1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }
};
