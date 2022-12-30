
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* high = head;
        Node* low = head;
        
        while(low != NULL && high != NULL && high->next != NULL){
            low = low->next;
            high = high->next->next;
            if(high == low){
                break;
            }
        }
            if(low == head){
                while(high->next != low){
                    high = high->next;    
                }
                high -> next =NULL;
            }
            else if(low == high){
                low = head;
                while(low -> next != high -> next){
                    low = low->next;
                    high = high->next;
                }
                high -> next= NULL;
            }
    }
};
