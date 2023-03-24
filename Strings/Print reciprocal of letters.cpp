#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string reciprocalString(string s)
    {
        // Write Your code here
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = 'z' - (s[i] -'a');
            }
            else if (s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = 'Z' - (s[i] -'A');
            }
            
            else if(s[i] == ' '){
                continue;
            }
        }
        return s;
    }
};
