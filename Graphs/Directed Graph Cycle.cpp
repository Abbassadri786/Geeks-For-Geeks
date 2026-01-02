class Solution {
  private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        // traverse for adjacent nodes;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)) return true;
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
        }
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};
