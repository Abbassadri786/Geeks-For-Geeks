#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
       map<int,int>ans;
       
       for(int i=0; i<n; i++){
           ans[a[i]]++;
           if(ans[a[i]]==k){
               return a[i];
           }
           
       }
       return -1;
    }
};
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
