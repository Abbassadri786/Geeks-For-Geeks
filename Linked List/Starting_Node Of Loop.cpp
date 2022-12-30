class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node* high = head;
        Node* low = head;
        while(high != NULL && low != NULL && high->next!=NULL){
            low = low->next;
            high = high->next->next;
            if(high == low){
                break;
            }
        }
        if(high!=low){
            return -1;
        }
        low = head;
        while(low != high){
            low = low->next;
            high = high->next;
        }
        return high->data;
    }
};
