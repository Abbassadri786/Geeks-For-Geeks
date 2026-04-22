/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node *node = q.front();
                q.pop();
                
                if(i==0){
                    ans.push_back(node->data);    
                }
                if(node -> left)q.push(node -> left);
                if(node -> right)q.push(node -> right);
            }
        }
        
        return ans;
        
    }
};
