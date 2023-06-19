//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    int findPosition(int inorder[], int element, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    Node* buildTreeUtil(int inorder[], int preorder[], int& preIndex, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int element = preorder[preIndex++];
        Node* root = new Node(element);

        if (start == end) {
            return root;
        }

        int inorderIndex = findPosition(inorder, element, start, end);

        root->left = buildTreeUtil(inorder, preorder, preIndex, start, inorderIndex - 1);
        root->right = buildTreeUtil(inorder, preorder, preIndex, inorderIndex + 1, end);

        return root;
    }

    Node* buildTree(int inorder[], int preorder[], int n) {
        int preIndex = 0;
        return buildTreeUtil(inorder, preorder, preIndex, 0, n - 1);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
