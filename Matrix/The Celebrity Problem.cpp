class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        int top = 0, down = n - 1;

        // Find possible candidate
        while(top < down) {
            if(mat[top][down] == 1) {
                // top knows down → top cannot be celeb
                top++;
            } 
            else {
                // top doesn't know down → down cannot be celeb
                down--;
            }
        }

        int cand = top;

        // Verify candidate
        for(int i = 0; i < n; i++) {
            if(i == cand) continue;
            
            // celeb knows no one & everyone knows celeb
            if(mat[cand][i] == 1 || mat[i][cand] == 0) {
                return -1;
            }
        }

        return cand;
    }
};
