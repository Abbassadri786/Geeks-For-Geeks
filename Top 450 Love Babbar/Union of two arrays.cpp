#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int,int>map;
        for(int i=0; i<n; i++){
            map[a[i]]++;
        }
        for(int i=0; i<m; i++){
            map[b[i]]++;
        }
        return map.size();
    }
};
