#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        map <char,int> freq;
        for(int i=0; i< s.length(); i++){
            freq[s[i]]++;
        }

        for(int i=0; i<freq.size(); i++){
            if(freq[s[i]] > 1){
                return s[i];
            }
        }
        return '#';
        
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
