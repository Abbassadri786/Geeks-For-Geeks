class Solution {
  private:
    bool isSafe(int node, vector<int> &color, vector<vector<int>> &edges, int col) {
// Check for adjacent nodes is it safe to place, wether adjacent has same color or diff
        
      // iterate through all edges
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // if node is connected to u or v
            if(u == node && color[v] == col) return false;
            if(v == node && color[u] == col) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<int> &color, int m, int v, vector<vector<int>> &edges) {
        if(node == v) return true;
      
        // run loop for each color which can be placed
        for(int col = 1; col <= m; col++) {
            if(isSafe(node, color, edges, col)) {
                color[node] = col;
                // return true if we are able to color it
                if(solve(node + 1, color, m, v, edges)) return true;
                // if not then backtrack and reset the color
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> color(v, 0);
        return solve(0, color, m, v, edges);
    }
};
