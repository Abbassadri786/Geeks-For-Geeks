// Back-end complete function Template for C++

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        
        const int MOD = 1e9 + 7;

        int totalSum = 0;
        for(auto &x: A){
            totalSum += x;
        }

        // If transformation not possible
        if(totalSum < abs(target) || (totalSum + target) % 2 != 0)
            return 0;

        // Required subset sum
        int exp = (totalSum + target) / 2;

        // dp[i][j] = number of ways to get sum j using first i elements
        vector<vector<long long>> dp(n+1, vector<long long>(exp+1, 0));

        // Base case: one way to form sum 0 (empty subset)
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        // Fill DP table
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= exp; j++){

                // If current element can be included
                if(A[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-A[i-1]] + dp[i-1][j]) % MOD;
                }
                else{
                    dp[i][j] = dp[i-1][j] % MOD;
                }
            }
        }

        return dp[n][exp];
    }
};
