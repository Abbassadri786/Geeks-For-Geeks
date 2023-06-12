//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr -> next;

        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        // Step 1: Reverse both the Linked List
        l1 = reverse(l1);
        l2 = reverse(l2);

        // Add 2 Linked List
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            // Calculate Sum including carry
            int sum = carry + l1 -> data + l2 -> data;
            // Find digit to create node for
            int digit = sum % 10;
            // Calculate carry generated
            carry = sum/10;

            // Create a new Node for the digit
            Node* newNode = new Node(digit);
            // Attach the new Node into ans Linked List
            if(ansHead == NULL){
                // First Node Insert kar rhe ho
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail -> next = newNode;
                ansTail = newNode;

            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        //Jab l1 ki length l2 se zyada ho
        while(l1 != NULL){
            int sum = carry + l1 -> data;
            int digit = sum % 10;
            carry = sum / 10;

            Node* newNode = new Node(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
            l1 = l1 -> next;
        }
        //Jab l2 ki length l1 se zyada ho
        while(l2 != NULL){
            int sum = carry + l2 -> data;
            int digit = sum % 10;
            carry = sum / 10;

            Node* newNode = new Node(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
            l2 = l2 -> next;
        }
        // Agar carry last me bach rha hoto
        while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            Node* newNode = new Node(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
        }

        ansHead = reverse(ansHead);
        return ansHead;        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
