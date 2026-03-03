class Solution {
  public:
    vector<int> sortByFreq(vector<int>& arr) {
        
        // Custom comparator
        auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
            if(a.first == b.first)
                return a.second > b.second;  // smaller value first
            return a.first < b.first;        // higher freq first
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxH(cmp);
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for(auto &itr: mp){
            maxH.push({itr.second, itr.first});
        }
        
        vector<int> ans;
        
        while(!maxH.empty()){
            int value = maxH.top().second;
            int freq  = maxH.top().first;
            maxH.pop();
            
            while(freq--){
                ans.push_back(value);
            }
        }
        
        return ans;
    }
};
