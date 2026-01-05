class Solution {
  private:
    void dfs(int node, int vis[], vector<int> adj[], vector<int> &temp){
        vis[node] = 1;
        temp.push_back(node);
        
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                dfs(nbr, vis, adj, temp);
            }
        }
    }
   
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // code here
        int vis[V] = {0};
        vector<vector<int>> ans;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i, vis, adj, temp);
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};
