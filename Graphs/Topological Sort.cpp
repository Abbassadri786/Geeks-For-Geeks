class Solution {
  private:
   void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
       vis[node] = 1;
       for(auto it: adj[node]){
           if(!vis[it]) {
               dfs(it, vis, st, adj);
           }
       }
       st.push(node);
   }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
        }
        
        int vis[V] = {0};
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
