// Aprpaoch 1: naive approach using PrefixMax and SuffixMax array in which total += min(leftMax, rightMax) - arr[i]
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> prefixMax(n), suffixMax(n);

        // prefix max
        prefixMax[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }

        // suffix max
        suffixMax[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            total += min(prefixMax[i], suffixMax[i]) - arr[i];
        }
        return total;
    }
};
