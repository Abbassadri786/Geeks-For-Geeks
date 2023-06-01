class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    // Using ordered map
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       map<char,int> freq;
       
       for(int i=0; i < S.length(); i++){
           freq[S[i]]++;
       }
       
       for(int i=0; i < S.length(); i++){
           if(freq[S[i]] == 1){
               return S[i];
               break;
           }
       }
       return '$';
       
    }

};
