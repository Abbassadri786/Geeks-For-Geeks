class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int x : arr){
            pq.push(x);
        }
        
        int sum = 0;
        
        while(pq.size() > 1){
            int r1 = pq.top(); pq.pop();
            int r2 = pq.top(); pq.pop();
            
            int cost = r1 + r2;
            sum += cost;
            
            pq.push(cost);
        }
        
        return sum;
    }
};
