#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr, arr+N);
      if(N == 0) return 0;
      
      int lastSmall = INT_MIN;
      int cnt = 0;
      int maxLen = 1;
      
      for(int i=0; i< N; i++){
          if(arr[i] - 1 == lastSmall){
              cnt++;
              lastSmall = arr[i];
          }
          else if(arr[i] != lastSmall){
              cnt = 1;
              lastSmall = arr[i];
          }
          
          maxLen = max(maxLen, cnt);
      }
      
      return maxLen;
    }
};
