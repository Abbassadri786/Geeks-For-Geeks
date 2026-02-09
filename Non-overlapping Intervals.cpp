class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int cnt = 1;
        int lastFreeTime = intervals[0][1];
        
        for(int i=0; i<n; i++){
            if(intervals[i][0] >= lastFreeTime){
                lastFreeTime = intervals[i][1];
                cnt++;
            }
        }
        
        return n - cnt;
    }
};
