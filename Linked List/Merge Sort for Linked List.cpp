//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* head1, Node* head2) {
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
    if(head1 == NULL){
        AnsTail -> next = head2;
    }
    if(head2 == NULL){
        AnsTail -> next = head1;
    }
    
    return AnsHead;       
    }
    Node* mergeSort(Node* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        Node* slow = head;
        Node* fast = head;
        Node* temp = NULL;
      
        // Find Mid using SLow and Fast method
        while(slow != NULL && fast != NULL){
            temp = slow;
            fast = fast-> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        // Break LL into two halves
        Node* left = head;
        Node* right = temp -> next;        
        temp -> next = NULL;
      
        //Sort Recursively
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge both Left and Right after sort
        Node* mergeList = merge(left,right);
        return mergeList;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
