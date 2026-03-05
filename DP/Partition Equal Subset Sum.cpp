class Solution {
    // Approach : Similar to 1/0 Knapsack and extention of subset sum
    // Bottom Up Tabulation 
  private:
   bool subsetSum(vector<int>& arr, int sum){
       int n = arr.size();
       vector<vector<bool>> dp(n+1, vector<bool> (sum+1,false));
       // base condition
       for(int i=0; i<n+1; i++){
           dp[i][0] = true; 
       }
       
       // filling up table
       for(int i=1; i < n+1; i++){
           for(int j=1; j < sum+1; j++){
               if(arr[i-1] <= j){
                   dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[n][sum];
   }
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(auto &i: arr){
            sum += i;
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        return subsetSum(arr, sum/2);
    }
};
