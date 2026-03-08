class Solution {
    // Similar to Knapsack Unbounded problem in 'take case' instead of [i-1] take i only 
  public:
    int cutRod(vector<int> &price) {

        int n = price.size();
        int size = n;  // rod length

        // length array represents available rod piece sizes
        vector<int> length(n);
        for(int i = 0; i < n; i++){
            length[i] = i + 1;
        }

        // dp[i][j] = max profit using first i lengths to make rod length j
        vector<vector<int>> dp(n+1, vector<int>(size+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= size; j++){

                // If current rod length can be used
                if(length[i-1] <= j){

                    // Unbounded choice → stay at same row when including
                    dp[i][j] = max(
                        price[i-1] + dp[i][j - length[i-1]],
                        dp[i-1][j]
                    );
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][size];
    }
};
