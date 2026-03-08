class Solution {
    // This problem similar to cnt no of subset = sum where[i-1] so use [i] only as take case can be used multiple times to form combinations
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        // base case
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        // filling up table
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1] <= j){
                                // unbounded knapsack
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
