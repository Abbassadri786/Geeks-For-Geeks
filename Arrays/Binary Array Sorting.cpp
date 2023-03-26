#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
       int cnt0 = 0, cnt1 = 0;
       for(int i=0; i<N; i++){
           if(A[i] == 0){
               cnt0++;
           }
           else{
               cnt1++;
           }
       }
       int k=0;
       for(int i=0; i<cnt0; i++)A[k++] = 0;
       for(int i=0; i<cnt1; i++)A[k++] = 1;
    }
};

int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
