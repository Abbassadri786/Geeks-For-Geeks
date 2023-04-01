#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int>pos;
        vector<int>neg;
        for(int i=0;i<n;i++){
            if(arr[i]>=0)
            pos.push_back(arr[i]);
            else
            neg.push_back(arr[i]);
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<pos.size()&&j<neg.size()){
            arr[k++]=pos[i];
            i++;
            arr[k++]=neg[j];
            j++;
        }
        while(i<pos.size()){
            arr[k++]=pos[i++];
        }
        while(j<neg.size()){
            arr[k++]=neg[j++];
        }
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
