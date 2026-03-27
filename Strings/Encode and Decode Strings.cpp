class Solution {
  private:
    const char delimiter = '/';

  public:
    string encode(vector<string>& s) {
        string encoded;
        
        for(auto &str: s){
            // store length of current string
            encoded += to_string(str.length()) + delimiter;
            
            // append actual string
            encoded += str;
        }
        
        return encoded;
    }

    vector<string> decode(string& s) {
        vector<string> decoded;
        
        int i = 0;
        while(i < s.length()){
            
            // find delimiter position
            int delimiterPos = s.find(delimiter, i);
            
            // extract length
            int len = stoi(s.substr(i, delimiterPos - i));
            
            // move pointer after delimiter
            i = delimiterPos + 1;
            
            // extract actual string
            string str = s.substr(i, len);
            decoded.push_back(str);
            
            // move pointer to next encoded part
            i += len;
        }
        
        return decoded;
    }
};
