
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string delAlternate(string S) {
        // code here
        string ans;
        
        for(int i=0; i<S.length(); i++){
            if(i%2==0){
                ans += S[i];
            }
            else{
                continue;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.delAlternate(S) << endl;
    }
    return 0;
}
