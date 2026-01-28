class Solution {
  private:
  
    bool isPossible(int row, int col, vector<int>& board, int n){
        int dupliRow = row;
        int dupliCol = col;
        
        while(row>=0 && col >=0){
            if(board[row] == col + 1){
                return false;
            }
            row--;
            col--;
        }
        
        row = dupliRow;
        col = dupliCol;
        
        while(col >= 0){
            if(board[row] == col + 1){
                return false;
            }
            col--;
        }
        
        row = dupliRow;
        col = dupliCol;
        
        while(row < n && col >=0){
            if(board[row] == col + 1){
                return false;
            }
            row++;
            col--;
        }
        
        return true;
        
    }  
    // placing queens col by col
    void solve(int col, vector<int>& board, vector<vector<int>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(isPossible(row, col, board, n)){
                board[row]= col + 1;
                solve(col + 1, board, ans, n);
                board[row] = 0;
            }
        }
    }
    
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> board(n, 0);
        
        solve(0, board, ans, n);
        return ans;
        
    }
};
