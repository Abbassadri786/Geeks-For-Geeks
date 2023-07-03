class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossibleSol(int A[], int N, int M, int sol){
        int pageSum = 0;
        // Pehle bande ka case maante hue
        int c = 1;
        
        for(int i = 0; i < N; i++){
            if(A[i] > sol){
                return false;
            }
            if( pageSum + A[i] > sol){
                // pehle bande ko allocation ho gai abb
                c++;
                pageSum = A[i];
                if(c > M){
                    return false;
                }
            }
            else{
                pageSum += A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int s = 0;
        int e = accumulate(A, A+N, 0);
        int ans = -1;
        
        while(s <= e){
            int mid = (s+e)>>1;
            if(isPossibleSol(A,N,M,mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
