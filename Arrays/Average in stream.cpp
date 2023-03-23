class Solution{
public:	
	vector<float> streamAvg(int arr[], int n) {
	    // code here
	    vector<float>ans;
	    float average =0.00;
	    for(int i=0; i<n; i++){
	            average = ((average * i) + arr[i]) / (i+1);
	            ans.push_back(average);
	    }
	    
	    return ans;
	}
};
