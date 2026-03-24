// Approach: Solve it using 2 pointer approach expand and check the pointers from center(outwards)
class Solution {
  private:
    void help(int start, int end, int &cnt, string &s){
        
        // expand while valid palindrome
        while(start >= 0 && end < s.length() && s[start] == s[end]){
            
            // count palindrome of length >= 2
            if(end - start + 1 >= 2){
                cnt++;
            }
            
            start--;
            end++;
        }
    }

  public:
    int countPS(string &s) {
        
        if(s.length() == 0) return 0;

        int cnt = 0;

        for(int i = 0; i < s.length(); i++){
            // odd-length centers
            help(i, i, cnt, s);
            // even-length centers
            help(i, i+1, cnt, s);
        }

        return cnt;
    }
};
