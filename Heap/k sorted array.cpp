class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // using max heap
        priority_queue<pair<int, int>> maxH;
        
        for(int i=0; i<n; i++){
            maxH.push({arr[i],i}); // storing elem along with its orignal index
        }
        int exp = n-1; // index traversing from back
        
        while(!maxH.empty()){
            int idx = maxH.top().second; // extract the orignal index
            maxH.pop();
            // if diff of orignal idx and sorted is more then k return NO
            if(abs(exp - idx) > k){
                return "No";
            }
            exp--;
        }
        
        return "Yes";
    }
};
