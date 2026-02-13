// Aprroach 1: standard two-pass greedy (left & right arrays)
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> left(n, 1), right(n, 1);
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = 1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i + 1]){
                right[i] = right[i+1] + 1;
            }
            else{
                right[i] = 1;
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += max(left[i], right[i]);
        }
        
        return sum;
    }
};

// Aprpaoch 2: More optimzed from above only using left array so SC = (N) and TC = (N)
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        // Step 1: Left to Right pass (same as your approach)
        vector<int> left(n, 1);
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // Step 2: Right to Left pass (optimized - no right array)
        int sum = 0;
        int right = 1;  // candies needed from right side for last child

        // Last index contribution
        sum += max(left[n - 1], right);

        for(int i = n - 2; i >= 0; i--) {
            int curr;

            // If current rating > next rating, need more candies than right neighbor
            if(arr[i] > arr[i + 1]) {
                curr = right + 1;
            } else {
                curr = 1;
            }

            sum += max(left[i], curr);

            // update right for next iteration (moving left)
            right = curr;
        }

        return sum;
    }
};

