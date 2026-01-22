// User function template for C++
class Solution {
  private:
        int lowerBound(const vector<int>& arr, int n, int x){
            int low = 0, high = n - 1;
    
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(arr[mid] >= x){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            return low;
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int cntMax = 0;
        int idx = -1;

        for(int i = 0; i < n; i++){
            int firstOneIdx = lowerBound(arr[i], m, 1);
            int cntOne = m - firstOneIdx;

            if(cntOne > cntMax){
                cntMax = cntOne;
                idx = i;
            }
        }
        return idx;
        
    }
};
