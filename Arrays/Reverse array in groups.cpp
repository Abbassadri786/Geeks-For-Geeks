#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverse(vector<long long>& arr , int s , int e){
        while(s < e){
            swap(arr[s] , arr[e]);
            s++,e--;
        }
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        int i=0;
        while(i< n-k){
            reverse(arr, i, i+k-1);
            i += k;
        }
        
        k = n%k;
        reverse(arr, i, i+k-1);
        
    }
};
