class Solution {
// Solve it using Sliding Window technique for at most K elements
  public:
    int characterReplacement(string& s, int k) {
        int n = s.length();
        
        int l = 0, r = 0;
        int maxF = 0;     // max frequency of any character in current window
        int maxLen = 0;   // answer
        
        int hash[26] = {0}; // frequency array for uppercase letters
        
        while(r < n){
            // include current character in window
            hash[s[r] - 'A']++;
            
            // update max frequency in current window
            maxF = max(maxF, hash[s[r] - 'A']);
            
            // if replacements needed > k, shrink window
            if((r - l + 1) - maxF > k){
                hash[s[l] - 'A']--;
                l++;
            }
            
            // update maximum valid window length
            maxLen = max(maxLen, r - l + 1);
            
            r++; // expand window
        }
        
        return maxLen;
    }
};
