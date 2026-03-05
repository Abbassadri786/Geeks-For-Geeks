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

class Solution {
  public:
    // Approach 2: Bottom Up Approach filling Memo table( Iterative Sol O(n²))
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int dp[n+1][sum+1];
        
        // Step 1 : Initialize Base condition in Memo Table
        for(int i=0; i < n+1; i++){
            for(int j=0; j < sum+1; j++){
                if(i == 0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        
        //Step 2: Fill whole memo table using reccursive core logic replacing n -> i and sum -> j
        for(int i=1; i< n+1; i++){
            for(int j=1; j<sum+1; j++){
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
};
