#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr+n);
        
        for(int i=0; i<n; i++){
            int l = i+1;
            int h = n-1;
            while(l < h){
                if(arr[i] + arr[l] + arr[h] == 0){
                    return true;
                }
                else if(arr[i] + arr[l] + arr[h] > 0){
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};

int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
