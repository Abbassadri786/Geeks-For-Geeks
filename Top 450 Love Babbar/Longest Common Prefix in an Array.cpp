#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        sort(arr, arr+N);
        string ans = "";
        string first = arr[0];
        string last = arr[N-1];
        
        for(int i=0; i<first.length(); i++){
            if(first[i] == last[i]){
                ans += first[i];
            }
            else{
                break;
            }
        }
        if(ans.length() == 0){
                ans += "-1";
        }
        return ans;
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
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
