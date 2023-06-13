//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    
    Node* AnsHead = NULL;
    Node* AnsTail = NULL;
    // First Traverse 1st node of both LL and Decide the Head and Tail to continue the process
    if(head1 -> data <= head2 -> data){
        AnsHead = head1;
        AnsTail = head1;
        head1 = head1 -> next;
    }
    else{
        AnsHead = head2;
        AnsTail = head2;
        head2 = head2-> next;
    }
    // Now Traverse Both LL and compare which node is smaller then insert that smaller node in AnsTail
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data <= head2 -> data){
            AnsTail -> next = head1;
            AnsTail = head1;
            head1 = head1 -> next;
        }
        else if(head1 -> data > head2 -> data){
            AnsTail -> next = head2;
            AnsTail = head2;
            head2 = head2 -> next;
        }
        
    // Now Take care of remaining list if any one of two is left (Due to length difference)    
    }
    while(head1 != NULL){
        AnsTail -> next = head1;
        AnsTail = head1;
        head1 = head1 -> next;
    }
    while(head2 != NULL){
        AnsTail -> next = head2;
        AnsTail = head2;
        head2 = head2 -> next;
    }
    
    return AnsHead;
    
    
}  
