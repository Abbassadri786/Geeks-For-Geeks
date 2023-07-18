class Solution{
public:
    int maxLength(string S){
        // code here
        int maxLength = 0;
        stack<int> stk;
        stk.push(-1); // Initialize stack with -1 as the base index

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLength = max(maxLength, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }

        return maxLength;
    }
};
