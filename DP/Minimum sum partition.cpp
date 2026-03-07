class Solution {
// Using Tabulation method, use of range and filling last row as min vector
// Extension of Subset Sum
  public:
    int minDifference(vector<int>& arr) {
        
        int n = arr.size();
        
        int range = 0;
        for(int x : arr){
            range += x;
        }

        // DP table
        vector<vector<bool>> dp(n+1, vector<bool>(range+1,false));

        // Base case
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        // Fill DP table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=range;j++){

                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // Store last row (possible subset sums)
        vector<int> v;
        for(int j=0;j<=range/2;j++){
            if(dp[n][j] == true){
                v.push_back(j);
            }
        }

        // Compute minimum difference
        int mini = INT_MAX;

        for(int i=0;i<v.size();i++){
            mini = min(mini, range - 2*v[i]);
        }

        return mini;
    }
};
