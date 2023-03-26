#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int freq[26] = {0};
        for(int i=0; i<str.length(); i++){
            freq[str[i]-'a']++;
        }
        int maxi = INT_MIN,pos;
        char ch;
        for(int i=0; i<26; i++){
            if(maxi <freq[i]){
                maxi = freq[i];
                pos = i;
            }
        }
        return pos + 'a';
    }

};
int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
