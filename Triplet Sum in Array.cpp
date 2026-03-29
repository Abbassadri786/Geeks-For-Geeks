class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else if(sum == target){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
