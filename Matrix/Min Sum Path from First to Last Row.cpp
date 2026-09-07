class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        if(n == 1) return *min_element(mat[0].begin(), mat[0].end());
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                if(j == 0){
                    mat[i][j] += min(mat[i-1][j], mat[i-1][j+1]);
                }
                else if(j == n-1){
                    mat[i][j] += min(mat[i-1][j], mat[i-1][j-1]);
                }
                else{
                    mat[i][j] += min(mat[i-1][j], min(mat[i-1][j-1], mat[i-1][j+1]));
                }
            }    
        }
        
        return *min_element(mat[n-1].begin(), mat[n-1].end());
    }
};
