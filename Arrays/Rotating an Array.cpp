#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        int ans[n];
        int k=0;
        for(int i=d; i<n; i++){
            ans[k++] = arr[i];
        }
        for(int i=0; i<d; i++){
            ans[k++] = arr[i];
        }
        for(int i=0; i<n; i++){
            arr[i] = ans[i];
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
