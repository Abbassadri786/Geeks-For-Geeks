//sliding window naturally counts at most K in O(n). Directly enforcing exactly K breaks the monotonic window property, making it harder to maintain efficiently.
// Approach : atmost(arr, k) - atMost(arr, k-1)
class Solution {
  private:
    int subArrays(vector<int>& arr, int k){
        if(k < 0) return 0;
        int n = arr.size();
        int r = 0, l = 0, odds = 0, cnt = 0;
        
        while( r < n){
            odds += arr[r] % 2;
            
            while(odds > k){
                odds -= arr[l] % 2;
                l++;
            }
            
            cnt += (r-l+1);
            r++;
        }
        
        return cnt;
    }
  public:
    int countSubarrays(vector<int>& arr, int k) {
        return subArrays(arr, k) - subArrays(arr, k-1);
        
    }
};
