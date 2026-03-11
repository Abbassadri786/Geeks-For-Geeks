class Solution {
  public:
    int minDeletions(string s1) {
        // Minimum deletions required to make string palindrome = length of string - length of Longest Palindromic Subsequence (LPS)

        int n = s1.length();

        // Create reversed string of s1
        string s2 = "";
        int end = n - 1;
        while(end >= 0){
            s2 += s1[end--];
        }

        // dp[i][j] will store the length of LCS
        // between first i characters of s1 and first j characters of s2
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Build LCS table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){

                // If characters match, extend the common subsequence
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Otherwise take the maximum by skipping
                    // one character from either string
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return n - dp[n][n];
    }
};
