class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i=0, j=0;
        int cnt = 0, maxCount = 0;
        
        while(i < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCount = max(maxCount, cnt);
        }
        
        return maxCount;
    }
};
