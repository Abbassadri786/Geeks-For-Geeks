class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0; i < N; i++){
            pq.push(A[i]);
        }
        
        long long sum = 0;
        
        // Remove first K1 elements
        for(int i = 0; i < K1; i++){
            pq.pop();
        }
        
        // Sum elements from K1+1 to K2-1
        for(int i = K1 + 1; i < K2; i++){
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
