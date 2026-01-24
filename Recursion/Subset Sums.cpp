// Fantastic problem for pick and not pick elements
class Solution {
  private:
    void sumSubset(int idx, int sum, vector<int>& arr, vector<int>& ans){
        if(idx == arr.size()){
            ans.push_back(sum);
            return;
        }
        //pick element
        sumSubset(idx + 1, sum + arr[idx], arr, ans);
        
        //not pick element
        sumSubset(idx+1, sum, arr, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {

        vector<int> ans;
        sumSubset(0, 0, arr, ans);
        return ans;
        
    }
};
