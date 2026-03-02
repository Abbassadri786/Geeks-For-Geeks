class Solution {
  public:
    string minWindow(string &s, string &p) {

        int n = s.length(), m = p.length();
        int l = 0, r = 0, cnt = 0, minLen = INT_MAX, sIndex = -1;
        unordered_map<char, int> hash;
        
        for(int i=0; i<m; i++){
            hash[p[i]]++;
        }
        
        while(r < n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            
            while(cnt == m){
                
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        
        return (sIndex == -1) ? "": s.substr(sIndex, minLen);
    }
};
