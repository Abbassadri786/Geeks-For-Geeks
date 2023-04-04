#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string,int>ans;
        for(int i=0; i<n; i++){
            ans[arr[i]]++;
        }
        int maxi = ans[arr[0]];
        int second_max = -1;
        string str1 = "";
        
        for(int i=0; i<n; i++){
            if(ans[arr[i]] > maxi){
                maxi = ans[arr[i]];
            }
            
        }
        for(int i=0; i<n; i++){
            if(ans[arr[i]] > second_max && ans[arr[i]] < maxi){
                second_max = ans[arr[i]];
                str1 = arr[i];
            }
        }
        return str1;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
