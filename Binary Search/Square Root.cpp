class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int ans = 1;
        int low = 1, high = n;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if((long long) mid * mid <= n){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
