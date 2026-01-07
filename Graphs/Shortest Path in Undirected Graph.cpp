class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // No vis array here just keep track of dis array using queue
        vector<int> adj[V];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dis(V, 1e9);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto nbr: adj[node]){
                if(dis[node] + 1 < dis[nbr]){
                    dis[nbr] = dis[node] + 1;
                    q.push(nbr);
                }
            }
        }
        //which are not reachable
        for(int i=0; i<V; i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        
        return dis;
        
    }
};
