/*
problem statement - Delete a Node from linked list without head pointer

*/



#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
// Function to delete the node without head
void deleteNodeWithoutHead(struct Node* pos)
{
    if (pos == NULL) // If linked list is empty
        return;
    else {
 
        if (pos->next == NULL) {
            printf("This is last node, require head, can't "
                   "be freed\n");
            return;
        }
 
        struct Node* temp = pos->next;
 
        // Copy data of the next node to current node
        pos->data = pos->next->data;
 
        // Perform conventional deletion
        pos->next = pos->next->next;
 
        free(temp);
    }
}
 
// Function to print the linked list
void print(Node* head)
{
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
 
    cout << "NULL";
}
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Driver Code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    cout << "Initial Linked List: \n";
    print(head);
    cout << endl << endl;
 
    // Delete 15 without sending head
    Node* del = head->next;
    deleteNodeWithoutHead(del);
 
    // Print the final linked list
    cout << "Final Linked List after deletion of 15:\n";
    print(head);
 
    return 0;
 
    // This code has been contributed by Striver
}
