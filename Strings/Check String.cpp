#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        bool check (string s)
        {
        	//code here.
        	int alpha[26] = {0};
        	for(int i=0; i< s.length(); i++){
        	    alpha[s[i]-'a']++;
        	}
        	for(int i=0; i<26; i++){
        	    if(alpha[i] == s.length()){
        	        return true;
        	    }
        	}
        	return false;
        }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
		string s;
		cin >> s;
		Solution ob;
		if (ob.check (s))
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}
