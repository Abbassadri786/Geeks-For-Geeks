class Solution {
    // Appraoch: solved using Bottom Up Tabulation
    // Knapsack 0/1 Variant and extension of subset Sum(return bool type)
  public:
    int perfectSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        int mod = 1e9 + 7; // GFG requires modulo (1e9+7) because answers can be very large.
        
        // Initialize DP
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // Base condition
        dp[0][0] = 1;
        
        // Filling up the table
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){

                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j] % mod;
                }

            }
        }

        return dp[n][target] % mod;
    }
};
