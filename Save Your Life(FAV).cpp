class Solution{
public:
// Its a Implementation of Kadane's Algo using Map to keep track on Ascii Value

      string maxSum(string w,char x[], int b[],int n){
          // Unordered map for redefining ascii value for some characters
          unordered_map<char, int>mp;
          for(int i=0; i<n; i++){
              mp[x[i]] = b[i];
          }
          int sum = 0, maxi = INT_MIN;
          string ans = "", temp = "";
          
          for(int i = 0; i < w.length(); i++){
            int ascii;
            // Finding Ascii value if already given as input
            if(mp.find(w[i]) != mp.end()){
                ascii = mp[w[i]];
                
            }
              // If not present then converting that perticular character into integer
            else{
                ascii = (int)w[i];
            }
            // Summing up the characters
            sum += ascii;
            temp += w[i];
            if(maxi < sum){
                maxi = sum;
              // If maximum then placing it in answer string
                ans = temp;
            }
            if(sum<0){
              // If sum negative then reset it
                sum = 0;
                temp="";
            }
          }
          
          return ans;
      }
};
