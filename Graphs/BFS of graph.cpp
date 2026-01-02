class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        
        int vis[adj.size()] = {0};
        vis[0] = 1;
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
