#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
      
        int first = -1,second = -1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i] == x){
                first = i;
            }
            else if(a[i] == y){
                second = i;
            }
            if(first != -1 && second != -1){
                mini = min(mini, abs(second - first));
            }
            
        }
        if(first == -1 || second == -1){
            return -1;
        }
        else{
            return mini;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
