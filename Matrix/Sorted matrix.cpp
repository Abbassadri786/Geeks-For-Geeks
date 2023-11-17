#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> temp;
        for(int i=0; i<N; i++){
            for(int j =0; j< N; j++){
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> ans(N, vector<int>(N, 0));

        // Populate the answer matrix with sorted elements
        int k = 0; // Index for the sorted vector
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans[i][j] = temp[k++];
            }
        }
        return ans;
    }
};
