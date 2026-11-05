class Solution {
  public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        queue<pair<int,pair<int,int>>>q;
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //{Stops,{Nodes, Dist}}
        vector<int> dist(n, 1e9);
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            
            q.pop();
            if(stop > k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjCost = it.second;
                if(cost + adjCost < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost + adjCost;
                    q.push({stop + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
