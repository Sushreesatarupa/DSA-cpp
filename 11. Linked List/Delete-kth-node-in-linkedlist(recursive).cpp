// Recursive CPP program to delete k-th node
// of a linked list
#include <bits/stdc++.h>
using namespace std;
 
class Node {
    public:
    int data;
    Node* next;
};
 
// Deletes k-th node and returns new header.
Node* deleteNode(Node* start, int k)
{
    // If invalid k
    if (k < 1)
       return start;
 
    // If linked list is empty
    if (start == NULL)
       return NULL;
  
    // Base case (start needs to be deleted)
    if (k == 1)
    {
        Node *res = start->next;
        delete(start);
        return res; 
    }
     
    start->next = deleteNode(start->next, k-1);
    return start;
}
 
/* Utility function to insert a node at the beginning */
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
  
/* Utility function to print a linked list */
void printList(struct Node *head)
{
    while (head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    printf("\n");
}
  
/* Driver program to test above functions */
int main()
{
    struct Node *head = NULL;
  
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
   
    int k = 3;
    head = deleteNode(head, k);
  
    printf("\nModified Linked List: ");
    printList(head);
  
    return 0;
}