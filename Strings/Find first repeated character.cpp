#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
string firstRepChar(string s)
{
    //code here.
    map<char,int> ans;
    string res = ""; 
    int found =0;
    for(int i=0; i<s.length(); i++){
        ans[s[i]]++;
        if(ans[s[i]] > 1){
            res += s[i];
            found = 1;
            return res;
        }
    }
    if (found == 0){
        res += "-1";
        return res;
    }
    
}
