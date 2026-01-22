class Solution {
  private:
   bool binaryS(vector<int> &arr, int target, int n){
       int low = 0, high = n-1;
       
       while(low <= high){
           int mid = (low+high)/2;
           if(arr[mid] == target){
               return true;
           }
           
           if(arr[mid] > target){
               high = mid -1;
           }
           else{
               low = mid + 1;
           }
       }
       return false;
   }
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            if(binaryS(mat[i], x, m)){
                return true;
            }    
        }
        return false;
        
    }
};
