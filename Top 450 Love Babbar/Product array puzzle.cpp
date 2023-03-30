#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        long long int prod=1;
        vector<long long int> ans;
        int j=0;
        while(j<n)
        {
            for(int i=0;i<n;i++)
            {
                if(j!=i)
                prod *= nums[i];
            }
            ans.push_back(prod);
            j++;
            prod =1;
        }
        return ans;
    }
};

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
