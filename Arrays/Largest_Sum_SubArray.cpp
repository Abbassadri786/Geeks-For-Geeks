#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(const vector<int> &arr) {
  int max_sum = arr[0];
  int current_sum = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    current_sum = max(arr[i], current_sum + arr[i]);
    max_sum = max(max_sum, current_sum);
  }
  return max_sum;
}

int main() {
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  cout << maxSubArraySum(arr) << std::endl;
  return 0;
}
//This implementation uses the Kadane's algorithm which runs in O(n) time and has a linear space complexity.




