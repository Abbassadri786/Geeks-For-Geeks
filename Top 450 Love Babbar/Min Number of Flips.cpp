//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int n = S.length();
    int flipsWithStart0 = 0, flipsWithStart1 = 0;

    // Initialize the counts for both starting with 0 and starting with 1
    for (int i = 0; i < n; i++) {
        // Check if the current character should be 0 for starting with 0
        if (i % 2 == 0 && S[i] != '0') {
            flipsWithStart0++;
        }
        // Check if the current character should be 1 for starting with 0
        else if (i % 2 == 1 && S[i] != '1') {
            flipsWithStart0++;
        }

        // Check if the current character should be 1 for starting with 1
        if (i % 2 == 0 && S[i] != '1') {
            flipsWithStart1++;
        }
        // Check if the current character should be 0 for starting with 1
        else if (i % 2 == 1 && S[i] != '0') {
            flipsWithStart1++;
        }
    }

    // Return the minimum of flips required for both starting possibilities
    return min(flipsWithStart0, flipsWithStart1);
    
}
