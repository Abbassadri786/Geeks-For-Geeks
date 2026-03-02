class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxH;
        for(int i=0; i<arr.size(); i++){
            maxH.push(arr[i]);
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        
        return maxH.top();
    }
};
