class Solution {
  public:
    int lcs(string &s1, string &s2) {
        
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] will store the length of LCS of
        // first i characters of s1 and first j characters of s2
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Build the DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                // If characters match, include this character in LCS
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                // If characters don't match, take the best of:
                // removing a character from s1 OR removing from s2
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Final answer: LCS length for full strings
        return dp[n][m];
    }
};
