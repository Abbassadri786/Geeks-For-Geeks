//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // By Default Max Heap
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        // Initialize the heap with the first k elements using pair
        for(int i=0 ; i<k; i++){
            pq.push({arr[i], i});
        }
        // The maximum element in the first window
        ans.push_back(pq.top().first);
        // Process the remaining elements
        for(int i = k; i < n; i++){
            // Add the current element to the heap
            pq.push({arr[i], i});
            // Remove elements that are outside the current
            // window
            while(pq.top().second <= i-k){
                pq.pop();
            }
            // The maximum element in the current window
            ans.push_back(pq.top().first);
            
        }
        return ans;
    }
};
        //Brute force Approach
        // vector<int> ans;
        // if(k > n){
        //     return ans;
        // }
        // int max = INT_MIN;
        // for(int i=0; i<= n-k; i++){
        //     max = arr[i];
        //     for(int j = 0; j < k; j++){
        //         if(arr[i+j] > max){
        //             max = arr[i+j];
        //         }
        //     }
        //     ans.push_back(max);
        // }
        
        // return ans;

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
