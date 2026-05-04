//Use DFS + memoization to compute longest increasing path from each cell, avoiding recomputation.
class Solution {
    int rows, cols;
    vector<vector<int>> cache;

    // 4 directions: up, left, down, right
    int dirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

  private:
    int dfs(vector<vector<int>> &matrix, int i, int j){
        
        // return cached result if already computed
        if(cache[i][j]) return cache[i][j];
        
        int max_path_dir = 0;

        for(auto dir : dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            // FIX: added missing && and correct boundary checks
            if(new_i >= 0 && new_i < rows &&
               new_j >= 0 && new_j < cols &&
               matrix[i][j] < matrix[new_i][new_j]){
                
                // FIX: call dfs on new cell, not same cell
                max_path_dir = max(max_path_dir, dfs(matrix, new_i, new_j));
            }
        }
        
        // include current cell
        cache[i][j] = max_path_dir + 1;
        return cache[i][j];
    }

  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        
        rows = n;   // FIX: wrong variable name earlier
        cols = m;

        cache = vector<vector<int>>(rows, vector<int>(cols, 0));

        int max_path = 0;
        
        for(int i = 0; i < rows; i++){   // FIX: used 'row' instead of 'rows'
            for(int j = 0; j < cols; j++){
                max_path = max(max_path, dfs(matrix, i, j));
            }
        }
        
        return max_path;
    }
};
