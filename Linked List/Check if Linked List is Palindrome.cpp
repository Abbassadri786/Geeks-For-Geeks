//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //If Linked List is empty
        if(head == NULL){
            return true;
        }
        // 1 Node wala case
        if(head -> next == NULL){
            return true;
        }
        // > then 1 node
        // Step 1 : Find Middle Node through Fast and Slow Pointer
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        // Here Slow Pointer points on Middle Node
        
        // Step 2: Reverse Linked List after middle/slow node
        Node * reverseLLHead = reverse(slow -> next);
        // Step 3 : Now start Comparing from start and after the middle
        Node* temp1 = head;
        Node* temp2 = reverseLLHead;
        
        while(temp2 != NULL){
            if(temp1 -> data != temp2 -> data){
                // Not a Palindrome
                return false;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
