// By Updating the curr pos node with the data of its next node

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *pos)
    {
       // Your code here
       if(pos == NULL){
           return;
       }
       
       Node* temp = pos->next;
       pos-> data = pos -> next -> data;
       pos-> next = pos -> next -> next;
       
       free(temp);
    }

};
