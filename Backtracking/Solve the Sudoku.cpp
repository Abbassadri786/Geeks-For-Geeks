class Solution {
private:
    bool rowUsed[9][10] = {0};
    bool colUsed[9][10] = {0};
    bool boxUsed[9][10] = {0};

    bool solve(vector<vector<int>> &mat) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Find empty cell
                if (mat[row][col] == 0) {

                    for (int num = 1; num <= 9; num++) {
                        int box = (row / 3) * 3 + (col / 3);

                        // O(1) validity check using hash arrays
                        if (!rowUsed[row][num] &&
                            !colUsed[col][num] &&
                            !boxUsed[box][num]) {

                            // Place number
                            mat[row][col] = num;
                            rowUsed[row][num] = 1;
                            colUsed[col][num] = 1;
                            boxUsed[box][num] = 1;

                            // Recurse
                            if (solve(mat)) return true;

                            // Backtrack
                            mat[row][col] = 0;
                            rowUsed[row][num] = 0;
                            colUsed[col][num] = 0;
                            boxUsed[box][num] = 0;
                        }
                    }
                    // No valid number fits here
                    return false;
                }
            }
        }
        // Board completely filled
        return true;
    }

public:
    void solveSudoku(vector<vector<int>> &mat) {

        // Pre-fill hash arrays from initial board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] != 0) {
                    int num = mat[row][col];
                    int box = (row / 3) * 3 + (col / 3);
                    rowUsed[row][num] = 1;
                    colUsed[col][num] = 1;
                    boxUsed[box][num] = 1;
                }
            }
        }

        solve(mat);
    }
};
