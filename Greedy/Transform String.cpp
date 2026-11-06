class Solution {
  public:
    int transform(string &s1, string &s2) {
        // pehle koshish yeh rahegi anagram he ya nahi yeh check karna
        vector<int> freq(256, 0);

        int n = s1.length(), m = s2.length();
        if(n != m) return -1;
        
        for(int i = 0; i < n; i++) {
            freq[(unsigned char)s1[i]]++;
            freq[(unsigned char)s2[i]]--;
        }
        // check karo agar freq array purna empty nahi he to fir impossible
        for(auto it: freq){
            if(it != 0){
                return -1;
            }
        }
        //right to left iterate karo
        int i = n-1, j = n-1;
        int ans = 0;
        //agar iterate karte samay kuch diff mile 
        while(i >=0 && j>=0){
            //If they don't match, the character in s1 needs to be moved to the front
            while(i>=0 && s1[i] != s2[j]){
                ans++;
                i--;
            }
            //If characters match, keep that character in its position and move both pointers.
            if(i>=0){
                i--;
                j--;
            }
        }
        
        return ans;
    }
};
