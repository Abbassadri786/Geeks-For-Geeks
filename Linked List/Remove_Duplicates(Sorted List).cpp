//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 
 Node* start = head;
 if(!start)return NULL;
 while(start->next != NULL){
     if(start->data == start->next->data){
         start->next = start->next->next;
     }
     else{
         start = start->next;
     }
 }
 return head;
}
