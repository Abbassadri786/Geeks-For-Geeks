#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string str){
        
        // Your code here
        int c=0;

        for(int i=0;i<n;i++){

            if(str[i]=='1')

            c++;

        }

        return (c*(c-1)/2);
    }
        

};

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}
