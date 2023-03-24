#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    vector<int>ans;
    // code here
    int first = -1;
    int last = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            first = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            last = i;
        }
    }
    ans.push_back(first);
    ans.push_back(last);
    
    return ans;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
