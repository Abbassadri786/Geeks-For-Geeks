//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	   void solve(string S, set<string> &ans, int index){
	        if(index >= S.length()){
	            ans.insert(S);
	            return;
	        }
	        
	        for(int j = index; j < S.length(); j++){
	            swap(S[index], S[j]);
	            solve(S, ans, index+1);
	            
	            //Backtracking
	            swap(S[index], S[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    int index = 0;
		    set<string> ans;
		    solve(S, ans, index);
		    
		    vector<string> result(ans.begin(), ans.end());
		    return result;
		}	
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
