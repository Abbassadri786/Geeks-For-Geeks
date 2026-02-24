// Appraoch 1: window always becomes valid before updating answer. (Using nested While loop to allow shrink multiple times)
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = -1; // GFG requires -1 if no valid substring
        
        unordered_map<char, int> mp;
        
        while (r < n) {
            // Expand window
            mp[s[r]]++;
            
            // Shrink window if distinct characters exceed k
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            
            // Update answer ONLY when exactly k distinct characters
            if (mp.size() == k) {
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        return maxLen;
    }
};

// Approach 2: Using if condition to allow shrink only once hence avoiding nested while loops
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n= s.length();
        int l=0, r=0, maxLen= -1;
        
        unordered_map<char, int> mp;
        
        while(r < n){
            mp[s[r]]++;
            
            if(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            
            if(mp.size() == k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        
        return maxLen;
    }
};
