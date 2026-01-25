// dp[idx] stores minimum palindromic partitions from idx to end
// Each index is computed once
// Huge pruning of recursion tree

class Solution {
private:
    bool isPalindrome(int start, int end, string &s){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    int solve(int idx, string &s, vector<int> &dp){
        if(idx == s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int mini = INT_MAX;

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(idx, i, s)){
                mini = min(mini, 1 + solve(i + 1, s, dp));
            }
        }
        return dp[idx] = mini;
    }

public:
    int palPartition(string &s) {
        int n = s.size();
        vector<int> dp(n, -1);

        // partitions - 1 = cuts
        return solve(0, s, dp) - 1;
    }
};
