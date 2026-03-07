class Solution {
    // Solved uisng equation:
    // S1 - S2 = diff
    // S1 + S2 = totalSum
    // S1 = (diff + totalSum) / 2
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        
        for(auto &i : arr){
            totalSum += i;
        }
        if((diff + totalSum) % 2 != 0) return 0;; // if odd sum total then not possible
        
        int target = (totalSum + diff) / 2;
        
        // Now comes the code similar to Count no. of subsets with given sum
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        // Base case
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
        
    }
};
