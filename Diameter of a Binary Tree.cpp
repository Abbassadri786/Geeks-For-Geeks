//The diameter (also called the width) of a binary tree is defined as the number of edges on the longest path between any two leaf nodes.

class Solution {
  private:
    int maxDepth(Node* node, int &ans){
        if(node == NULL){
            return 0;
        }
        // Recursively compute height of left subtree
        int l = maxDepth(node->left, ans);
        int r = maxDepth(node -> right, ans);

        // Diameter at current node = number of edges in longest path
        // passing through this node = left height + right height
        // (since height is in terms of nodes, l + r gives edges)
        ans = max(ans, l+r);
        
        return 1+ max(l,r);
    }
  public:
    int diameter(Node* root) {
        int ans = 0;
        maxDepth(root, ans);
        
        return ans;
    }
};
