class Solution {
  private:
    void solve(int i, int j, int n, vector<string>& ans, string tmp, vector<vector<int>>& vis, vector<vector<int>>& maze) {

        if(i == n-1 && j == n-1) {
            ans.push_back(tmp);
            return;
        }

        // Mark current cell as visited ONCE
        vis[i][j] = 1;

        // Down
        if(i+1 < n && !vis[i+1][j] && maze[i+1][j] == 1) {
            solve(i+1, j, n, ans, tmp + 'D', vis, maze);
        }

        // Left
        if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1] == 1) {
            solve(i, j-1, n, ans, tmp + 'L', vis, maze);
        }

        // Right
        if(j+1 < n && !vis[i][j+1] && maze[i][j+1] == 1) {
            solve(i, j+1, n, ans, tmp + 'R', vis, maze);
        }

        // Up
        if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j] == 1) {
            solve(i-1, j, n, ans, tmp + 'U', vis, maze);
        }

        // Backtrack
        vis[i][j] = 0;
    }

  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if(maze[0][0] == 1)solve(0, 0, n, ans, "", vis, maze);

        return ans;
    }
};
