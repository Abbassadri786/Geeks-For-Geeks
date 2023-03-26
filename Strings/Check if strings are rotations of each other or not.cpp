#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length() != s2.length()){
            return false;
        }
        string ans = s1 + s1 ;
        if(ans.find(s2) != string::npos){
            return true;
        }
        return false;
        // Your code here
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
