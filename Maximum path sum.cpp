class Solution {
  private:
    int maxPathDown(Node *node, int &maxi){
        
        // Base case: if node is NULL, it contributes 0
        if(node == NULL) return 0;
        
        // Recursively get max path sum from left subtree
        // Ignore negative contributions by taking max with 0
        int left = max(0, maxPathDown(node->left, maxi));
        
        // Same for right subtree
        int right = max(0, maxPathDown(node->right, maxi));
        
        // Case 1: Path passes THROUGH current node
        // (left subtree + node + right subtree)
        // This could be the maximum path in the tree
        maxi = max(maxi, left + right + node->data);
        
        // Case 2: Return max path going upward to parent
        // Only one side can be chosen (no split allowed upward)
        return max(left, right) + node->data;
    }

  public:
  
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};
