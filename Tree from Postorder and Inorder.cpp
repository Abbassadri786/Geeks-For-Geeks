//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    int findPosition(int inorder[], int size, int element){

        for(int i = 0; i < size; i++){
            if(element == inorder[i]){
                return i;
                break;
            }
        }
        return -1;
    }
    Node* buildBT(int inorder[], int postorder[], int &postIndex, int size, int indexAtStart, int indexAtEnd){
        //Base Case
        if(postIndex < 0 || indexAtStart > indexAtEnd){
            return NULL;
        }
        //Find the root element in the postOrder array and traverse according to inOrder array
        int element = postorder[postIndex--];
        Node* root = new Node(element);

        int pos = findPosition(inorder, size, element);
        //Root -> right solve reccursively
        root -> right = buildBT(inorder, postorder, postIndex, size, pos + 1, indexAtEnd);
        //Root -> left solve reccursively
        root -> left = buildBT(inorder, postorder, postIndex, size, indexAtStart, pos - 1);

        return root;
    }
Node *buildTree(int inorder[], int postorder[], int n) {
        int postIndex = n - 1, indexAtStart = 0, indexAtEnd = n - 1, size = n;
        Node* root = buildBT(inorder, postorder, postIndex, size, indexAtStart, indexAtEnd);
        return root;
}
