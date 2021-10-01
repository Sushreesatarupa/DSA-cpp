//question - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1




class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
         Node* current = head;
        Node* prev = NULL; Node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
};
    
