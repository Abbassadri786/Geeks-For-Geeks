//Apraoch using Topo sort and relax algo
class Solution {
  private:
    void toposort(int node, vector<pair<int,int>> adj[],
                  vector<int> &vis, stack<int> &st){
        vis[node] = 1;

        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                toposort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<pair<int,int>> adj[V];
        for(int i = 0; i < E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 1: Topological sort
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                toposort(i, adj, vis, st);
            }
        }

        // Step 2: Distance relaxation
        vector<int> dis(V, 1e9);
        dis[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(dis[node] != 1e9){   // ✅ important check
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(dis[node] + wt < dis[v]){
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }

        // Step 3: Convert unreachable to -1
        for(int i = 0; i < V; i++){
            if(dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};
