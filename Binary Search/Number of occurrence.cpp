class Solution {
private:
    int lowerB(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] >= target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperB(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] > target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int lb = lowerB(arr, target);

        int Occ = ((upperB(arr, target) -1) - lb)  + 1;
        return Occ;
        
    }
};
