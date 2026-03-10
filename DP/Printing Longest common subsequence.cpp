class Solution {
  public:
    string printLCS(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // dp Table
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n, j = m; 
        string ans = "";
        
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--, j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        return reverse(ans.begin(), ans.end());
    }
};
