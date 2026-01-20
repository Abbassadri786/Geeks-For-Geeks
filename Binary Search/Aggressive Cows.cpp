class Solution {
  private:
    bool isPossible(vector<int> &stalls, int k, int dist){
        int cntCows = 1;          // first cow placed
        int last = stalls[0];

        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last >= dist){
                cntCows++;
                last = stalls[i];
            }
        }
        return cntCows >= k;
    }

  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());  // 🔴 REQUIRED

        int n = stalls.size();
        int low = 1;                          // minimum possible distance
        int high = stalls[n-1] - stalls[0];  // maximum possible distance
        int ans = 0;

        while(low <= high){
            int mid = (high + low) / 2;

            if(isPossible(stalls, k, mid)){
                ans = mid;        // store valid answer
                low = mid + 1;    // try for bigger distance
            }
            else{
                high = mid - 1;   // reduce distance
            }
        }
        return ans;
    }
};
