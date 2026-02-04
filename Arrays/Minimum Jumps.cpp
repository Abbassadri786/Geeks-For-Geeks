class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;

        int jumps = 0;
        int maxReach = 0;
        int currEnd = 0;

        for(int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + arr[i]);

            if(i == currEnd) {
                jumps++;
                currEnd = maxReach;

                if(currEnd >= n - 1)
                    break;
            }

            if(i >= maxReach)
                return -1;
        }

        return jumps;
    }
};
