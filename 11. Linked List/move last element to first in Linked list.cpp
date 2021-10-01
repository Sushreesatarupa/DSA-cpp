/*
Here we have created a function to move the last element of a Linked List and
put it at the Front of the Singly Linked List.

Example:
        Input: 1->2->3->4->5
        Output: 5->1->2->3->4
 
Approach:
  Start traversing the linked-list till end node is reached. 
  Using two pointers: first to store the address of last node and other to store address of the second last node. 
  When we reach the end of loop, we will be doing following operations.
  
  i) Make second last as last (secLast->next = NULL).
  ii) Set next of last as head (last->next = *head_ref).
  iii) Make last as head ( *head_ref = last)
  
Below is the c++ implementation of the same problem discussed above
*/

#include <bits/stdc++.h>
using namespace std;

// A linked list node 
class Node
{
	public:
	int data;
	Node *next;
};

/* We are using a double pointer
head_ref here because we change
head of the linked list inside
this function.*/

void moveToFront(Node **head_ref)
{
	/* If linked list is empty, or
	it contains only one node,
	then nothing needs to be done,
	simply return */
  
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return;

	/* Initialize second last
	and last pointers */
  
	Node *secLast = NULL;
	Node *last = *head_ref;

	/*After this loop secLast contains
	address of second last node and
	last contains address of last node in Linked List */
  
	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}

	// Set the next of second last as NULL
	secLast->next = NULL;

	// Set next of last as head node 
  
	last->next = *head_ref;

	/* Change the head pointer
	to point to last node now */
  
	*head_ref = last;
}

/* UTILITY FUNCTIONS */
/* Function to add a node
at the beginning of Linked List */

void push(Node** head_ref, int new_data)
{
	// allocate node 
	Node* new_node = new Node();

	// put in the data 
	new_node->data = new_data;

	// link the old list off the new node 
	new_node->next = (*head_ref);

	// move the head to point to the new node 
	(*head_ref) = new_node;
}


// Function to print nodes in a given linked list
void printList(Node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

// Driver code 
int main()
{
	Node *start = NULL;

	/* The constructed linked list will be:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	cout<<"Linked list before moving last to front\n";
	printList(start);

	moveToFront(&start);

	cout<<"\nLinked list after removing last to front\n";
	printList(start);
	return 0;
}
