class Solution {
public:
    bool canAttend(vector<vector<int>>& arr) {
        int n = arr.size();

        // sort meetings by end time
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // the time when the last attended meeting ended Before this time, the person is busy
        int freeTime = 0;

        // check each meeting
        for(int i = 0; i < n; i++) {
            if(arr[i][0] >= freeTime) {
                freeTime = arr[i][1];
            } else {
                return false;
            }
        }

        return true;
    }
};
