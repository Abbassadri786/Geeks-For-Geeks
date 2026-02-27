class Solution {
  private:
    int subArrays(vector<int>& arr, int target){
        if(target < 0) return 0;
        
        int n= arr.size();
        int r = 0, l = 0, sum = 0, cnt = 0;
        
        while(r < n){
            sum += arr[r];
            
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            cnt += (r- l +1);
            r++;
        }
        
        return cnt;
    }
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        return subArrays(arr, target) - subArrays(arr, target -1);
        
    }
};
