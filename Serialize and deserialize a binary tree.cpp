/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    // Serialize using BFS (level-order) store the traveral in vector
    vector<int> serialize(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            if(node == NULL){
                ans.push_back(-1); // use -1 as NULL marker (safe assumption in GFG)
            }
            else{
                ans.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return ans;
    }

    // Deserialize using BFS
    Node *deSerialize(vector<int> &arr) {
        if(arr.size() == 0) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1; // start from next element

        while(!q.empty() && i < arr.size()){
            Node* node = q.front();
            q.pop();

            // Left child
            if(arr[i] == -1){
                node->left = NULL;
            }
            else{
                Node* leftNode = new Node(arr[i]);
                node->left = leftNode;
                q.push(leftNode);
            }
            i++;

            // Right child
            if(i < arr.size()){
                if(arr[i] == -1){
                    node->right = NULL;
                }
                else{
                    Node* rightNode = new Node(arr[i]);
                    node->right = rightNode;
                    q.push(rightNode);
                }
                i++;
            }
        }

        return root;
    }
};
