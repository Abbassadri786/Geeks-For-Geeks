#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
        map<int,int> m;

        for(int i=0; i<n; i++){

            m[arr[i]]++;

        }

        for(auto x: m){

            if(x.second % 2 !=0)

              return x.first;

        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
