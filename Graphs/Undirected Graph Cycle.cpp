class Solution {
  private:
    bool detect(int src, vector<int> adj[], vector<int>& vis){
        
        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent){
                    return true;       // cycle found
                }
            }
        }
        return false;
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        // build adjacency list from edge list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V,0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
