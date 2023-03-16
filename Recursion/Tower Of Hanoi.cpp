void towerOfHanoi(int N, int src, int dst, int helper, long long &cnt){
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<src<<" to rod "<<dst<<endl;
            cnt++;
            return;
        }
        towerOfHanoi(N-1,src,helper,dst,cnt);
        
        
        cout<<"move disk "<<N<<" from rod "<<src<<" to rod "<<dst<<endl;
        
        towerOfHanoi(N-1,helper,dst,src,cnt);
        cnt++;
    }

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int src, int dst, int helper) {
        // Your code here
        long long cnt = 0;
        towerOfHanoi(N,src,dst,helper,cnt);
        return cnt;
        
    }
