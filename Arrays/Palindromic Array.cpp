class Solution {
public:
    bool PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0; i<n; i++){
    	    string idx = to_string(a[i]);
    	    int s =0, e = idx.size()-1;
    	    while(s<e){
    	        if(idx[s] != idx[e]){
    	            return false;
    	        }
    	        s++,e--;
    	    }
    	}
    	return true;
    }
};
