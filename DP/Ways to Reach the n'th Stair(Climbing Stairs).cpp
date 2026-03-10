class Solution {
  public:
    int countWays(int n) {
        
        // dp[i] = number of ways to reach step i
        vector<int> dp(n+1, 0);

        // Base case: one way to stay at step 0
        dp[0] = 1;

        // Build DP table
        for(int i = 1; i <= n; i++){
            
            // Take 1 step
            dp[i] += dp[i-1];

            // Take 2 steps (if possible)
            if(i >= 2){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};
