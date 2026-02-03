// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        long long waitTime =0, t = 0;
        int n = bt.size();
        
        for(int i=0; i<n; i++){
            waitTime += t;
            t += bt[i];
        }
        return (waitTime/n);
        
    }
};
