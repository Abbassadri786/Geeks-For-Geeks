class Solution {
  public:
    int longestPalinSubseq(string &s1) {

        int n = s1.length();
        
        // Create reversed string
        string s2 = "";
        int end = n - 1;
        while(end >= 0){
            s2 += s1[end--];
        }

        // LCS DP table
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                
                // If characters match
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
};
