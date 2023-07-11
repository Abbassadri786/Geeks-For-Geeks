class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // doing xor to see alternate bits 
        int num = a ^ b;
        int res = 0;
        
        while(num != 0){
            // To find number of set bits
            num = num & (num-1);
            // count no. of set bits
            res++;
        }
        return res;
    }
};
