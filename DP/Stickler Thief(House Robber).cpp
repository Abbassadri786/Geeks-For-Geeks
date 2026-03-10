class Solution {
    // Using 1D Dp, Pick(alternate neighbor) and Not Pick(adjacent ones) logic
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        // extra space so we can safely access i+1 and i+2
        vector<int> dp(n+2, 0);
        
        // fill DP from right to left
        for(int i=n-1; i>=0; i--){
            // pick current house + skip next house
            int pick = arr[i] + dp[i+2];
            
            // skip current house
            int Not_pick = dp[i+1];
            
            dp[i] = max(pick, Not_pick);
        }
        
        return dp[0];
        
    }
};
