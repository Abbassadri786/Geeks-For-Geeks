class Solution {
    // Similar to unbounded kanpsack
  public:
    int minCoins(vector<int> &coins, int sum) {

        int n = coins.size();

        // dp[i][j] = minimum coins needed to make sum j using first i coins
        vector<vector<int>> dp(n+1, vector<int>(sum+1, INT_MAX - 1));

        // Base case: 0 coins needed to make sum 0
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        // Initialize second row (using only first coin)
        for(int j = 1; j <= sum; j++){
            if(j % coins[0] == 0){
                dp[1][j] = j / coins[0];
            }
        }

        // Fill DP table
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= sum; j++){

                if(coins[i-1] <= j){
                    // Unbounded choice → stay in same row
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (dp[n][sum] == INT_MAX - 1) ? -1 : dp[n][sum];
    }
};
