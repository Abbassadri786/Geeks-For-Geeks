class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

        int n = arr.size();

        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        // Step 2: Initialize with first interval
        ans.push_back(arr[0]);

        // Step 3: Traverse and merge
        for(int i = 1; i < n; i++){
            //last is a reference, NOT a copy
            //directly updates the actual element inside ans
            vector<int> &last = ans.back();

            // If overlapping → merge
            if(arr[i][0] <= last[1]){
                last[1] = max(last[1], arr[i][1]);
            }
            else{
                // No overlap → add new interval
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};
