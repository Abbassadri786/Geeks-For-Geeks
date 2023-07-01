//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
        vector<int> result;
        int i = n - 1, j = m - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i];
                i--;
            }
            
            if (j >= 0) {
                sum += b[j];
                j--;
            }
            
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        
        string ans;
        bool leadingZero = true;
        
        for (int digit : result) {
            if (digit != 0)
                leadingZero = false;
            
            if (!leadingZero)
                ans += to_string(digit);
        }
        
        if (ans.empty())
            ans = "0";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends
