#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int firstOccur = -1, lastOccur = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                firstOccur = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                lastOccur = i;
            }
        }
        
        return {firstOccur, lastOccur};
        
    }
};
