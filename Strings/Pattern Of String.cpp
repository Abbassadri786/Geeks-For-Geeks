
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	vector<string> pattern(string S)
	{
	    // Your code goes here
	    vector<string> res;
	    
	    
	    int n = S.length();
	    
	    for(int i = n; i > 0; i--){
	        string ans = "";
	        for(int j=0; j<i; j++){
	            ans += S[j];
	        }
	        res.push_back(ans);
	        
	    }
	    return res;
	}

};
