#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxCount = 0;
	    int countRow = -1;
	    
	    for(int i=0; i<n; i++){
	       int count = 0;
	        for(int j=0; j<m; j++){
	            if(arr[i][j] == 1){
	                count++;
	            }
	        }
	        if(maxCount < count){
	            maxCount = count;
	            countRow = i;
	        }
	    }
	    return countRow;

	}
};
