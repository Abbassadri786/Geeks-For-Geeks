class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<char, int> hash;
        
        while(r < n){
            if(hash.find(s[r]) != hash.end() && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
            
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        
        return maxLen;
        
    }
};
