class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        map<int, int> freq;
        map<int, int> end;

        for (int x : arr)
            freq[x]++;

        for (int x : arr) {
            if (freq[x] == 0)
                continue;

            freq[x]--;

            // Extend an existing subsequence
            if (end[x - 1] > 0) {
                end[x - 1]--;
                end[x]++;
            }
            else {
                // Start a new subsequence of length at least k
                for (int i = 1; i < k; i++) {
                    if (freq[x + i] == 0)
                        return false;

                    freq[x + i]--;
                }

                end[x + k - 1]++;
            }
        }

        return true;
    }
  };
