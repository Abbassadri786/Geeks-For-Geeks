class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        
        // Max heap storing {distance, value}
        priority_queue<pair<int,int>> maxH;
        
        for(int i = 0; i < arr.size(); i++) {
            
            if(arr[i] == x) continue;  // Skip x itself
            
            int dist = abs(arr[i] - x);
            
            // Push distance and NEGATIVE value
            // so smaller value gets higher priority to remove
            maxH.push({dist, -arr[i]});
            
            if(maxH.size() > k) {
                maxH.pop();
            }
        }
        
        vector<int> ans;
        
        while(!maxH.empty()) {
            ans.push_back(-maxH.top().second);  // restore value
            maxH.pop();
        }
        
        // Sort as per requirement
        sort(ans.begin(), ans.end(), [&](int a, int b){
            int d1 = abs(a - x);
            int d2 = abs(b - x);
            
            if(d1 == d2)
                return a > b;  // larger element first
            return d1 < d2;    // smaller distance first
        });
        
        return ans;
    }
};
