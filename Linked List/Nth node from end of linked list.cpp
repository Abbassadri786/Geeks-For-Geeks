/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           int len=0;
           Node* temp = head;
           while(temp != NULL){
               temp = temp -> next;
               len++;
           }
           if(n > len){
               return -1;
           }
           temp = head;
           
           for(int i=0; i < len - n; i++){
               temp = temp->next;
           }
           return temp->data;
    }
};
