class Solution {
  public:
    void findNextGen(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int liveCnt = 0;
                for(int k=0; k<8; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    
                    if(newX>=0 && newX<n && newY>=0 && newY<m && (mat[newX][newY] == 1 || mat[newX][newY] == 2)){
                        liveCnt++;
                    }
                }
                
                if(mat[i][j] == 1){
                    if(liveCnt<2 || liveCnt>3){
                        mat[i][j] = 2; //live -> dead
                    }
                }
                else{
                    if(liveCnt == 3){
                        mat[i][j] =3; // dead -> live
                    }
                }
                    
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2) mat[i][j] = 0;
                if(mat[i][j] == 3) mat[i][j] = 1;
            }
        }
        
    }
};
