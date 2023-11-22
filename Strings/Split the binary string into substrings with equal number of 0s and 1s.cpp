#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int zero = 0;
        int one = 0;
        int cnt = 0;
        
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '0'){
                zero++;
            }
            else{
                one++;
            }
            if(one == zero){
                cnt++;
            }
            
        }
        if(one != zero){
            return -1;
        }
        return cnt;
    }
};
