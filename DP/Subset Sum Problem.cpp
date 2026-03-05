class Solution {
    // Appraoch : Top Down (Memoization)
    
    int dp[205][10005];  // memo table
private:
    bool helper(vector<int>& arr, int sum, int n){
        
        // Base cases
        if(sum == 0) return true;
        if(n == 0) return false;
        
        // Check memo
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        // Choice diagram
        if(arr[n-1] <= sum){
            return dp[n][sum] =
                helper(arr, sum - arr[n-1], n-1) ||
                helper(arr, sum, n-1);
        }
        else{
            return dp[n][sum] =
                helper(arr, sum, n-1);
        }
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        memset(dp, -1, sizeof(dp)); // initialize DP
        
        int n = arr.size();
        
        return helper(arr, sum, n);
    }
};
