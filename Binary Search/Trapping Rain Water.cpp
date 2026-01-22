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


// Appraoch 2: using 2 pointer approach w/o using external space
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l = 0, r = n-1;
        int leftMax = 0, rightMax = 0, total = 0;
        
        while(l <= r){
            // someone on right is greater
            if(arr[l] <= arr[r]){
                if(leftMax > arr[l]){
                    total += leftMax - arr[l];
                }
                else{
                    leftMax = arr[l];
                }
                l++;
            }
            else{
                if(rightMax > arr[r]){
                    total += rightMax - arr[r];
                }
                else{
                    rightMax = arr[r];
                }
                r--;
            }
        }
        return total;
        
    }
};
