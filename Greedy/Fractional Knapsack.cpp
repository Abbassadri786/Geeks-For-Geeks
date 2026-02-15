class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<pair<int, int>> arr;
        arr.reserve(n); // avoids reallocations (space optimized)

        for(int i = 0; i < n; i++) {
            arr.emplace_back(val[i], wt[i]);
        }

        // Sort by value/weight ratio in descending order (Greedy core)
        sort(arr.begin(), arr.end(), [](pair<int,int> &a, pair<int,int> &b) {
            double r1 = (double)a.first / a.second;
            double r2 = (double)b.first / b.second;
            return r1 > r2;
        });

        double totalVal = 0.0;

        for(int i = 0; i < n; i++) {
            int value = arr[i].first;
            int weight = arr[i].second;

            // Take full item if possible
            if(weight <= capacity) {
                totalVal += value;
                capacity -= weight;
            }
            else {
                // Take fractional part
                double fraction = (double)value / weight;
                totalVal += fraction * capacity;
                break; // knapsack is full
            }
        }

        return totalVal;
    }
};
