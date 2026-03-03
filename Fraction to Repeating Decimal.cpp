class Solution {
  public:
    string calculateFraction(int a, int b) {
        string result = "";
        
        // Handle integer part
        int integerPart = a / b;
        result += to_string(integerPart);
        
        int remainder = a % b;
        
        // If no remainder, no fractional part
        if (remainder == 0) {
            return result;
        }
        
        result += ".";  // Add decimal point
        
        // Map to store remainder and its position in result string
        unordered_map<int, int> mp;
        
        while (remainder != 0) {
            
            // If remainder seen before, it's repeating
            if (mp.find(remainder) != mp.end()) {
                int pos = mp[remainder];
                result.insert(pos, "(");
                result += ")";
                break;
            }
            
            // Store position of remainder
            mp[remainder] = result.length();
            
            remainder *= 10;
            int digit = remainder / b;
            result += to_string(digit);
            
            remainder %= b;
        }
        
        return result;
    }
};
