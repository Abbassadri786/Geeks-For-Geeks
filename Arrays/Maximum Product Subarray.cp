//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
        long long suffix = 1;
        long long prefix = 1;
        long long maxi = INT_MIN;
        
        for(int i=0; i<n; i++){
            
            if(suffix == 0) suffix = 1;
            if(prefix == 0) prefix = 1;
            
            prefix *= arr[i];
            suffix *= arr[n-i-1];
            
            maxi = max(maxi, max(prefix, suffix));
        }
        
	    return maxi;
	}
};
