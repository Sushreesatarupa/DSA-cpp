// Linked list is an linear data structure. It has dynamic memory i.e. it can be changed at any time inside heap. Node deletion and addition is simple 
// in linked list.

#include <bits/stdc++.h>
using namespace std;

// Basic linked list class
class node{
    public:
        int data;
        node* next;
        node(int val){                  // constructor
            data = val;
            next = NULL;
        }
};

// Function to insert node at tail i.e. at end
void insertionAtTail(node* &head , int val){
    node* newNodeVal = new node(val);               // creating a node of val  i.e.   data = val and next = NULL
    if(head==NULL){                                 // Checking if linked list is empty or not
       head = newNodeVal;                           // Empty then add newNodeVal to head
       return;
    }
    node* temp = head;                   // created another value as head is with reference bcoz transversing will transverse through actual linked list
    while(temp->next != NULL){          // transversing through linked list to reach at end;
        temp = temp->next;
    }
    temp->next = newNodeVal;            // Adding newNodeVal at last of linked list
}


// Function to insert at head i.e. at start
void insertionAtHead(node* &head , int val){
    node* newNodeVal = new node(val);
    newNodeVal->next = head;                    // new node pointing to head
    head = newNodeVal;                          // replaced head with new node with complete linked list
}


// Function to search an node data in linked list
bool searchingInLinkedList(node* &head , int key){
    cout<<key<<" : ";
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}


// Function  to delete node at head
void deletionAtHead(node* &head){
    if(head == NULL)
        return;
    node* todelete = head;
    head = head->next;
    delete todelete;
}


// Function to delete a node in between
void deletion(node* &head , int key){
    if(head == NULL)
        return;
    if(head->next == NULL){
        deletionAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != key){                         // Iterating until we get our deleting node
        temp = temp->next;  
    }
    node* todelete = temp->next;                            // node to be deleted
    temp->next = temp->next->next;                          // prev node now points to next node next to the node which is to be deleted
    delete todelete;                                        // deleting pointer
}


// Function to reversing a linked list - two methods  =>    1. Iterator Method        2. Recursive Method
// 1. Iterator Method
void reversingLinkedListIteratorMethod(node* &head){
    if(head == NULL or head->next == NULL)
        return;
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
}

// 2. Recursive Method
node* reversingLinkedListRecursiveMethod(node* &head){
    if(head == NULL or head->next == NULL)
        return head;
    node* newRecursiveReversedNodeHead = reversingLinkedListRecursiveMethod(head->next);                    // recursive call for next nodes
    head->next->next = head;                                                                    // last is head and last is pointing to null
    head->next = NULL;
    return newRecursiveReversedNodeHead;
}


// Function to reverse k-nodes of a linked list
node* reverse_K_Nodes(node* &head , int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr != NULL and count<k){                         // Iterator method to reverse linked list here, only k-nodes linked list
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr != NULL)
        head->next = reverse_K_Nodes(nextptr,k);
    return prevptr;
}


// Function to append last k-nodes at starting in a linked list
// Length of linked list
int length_of_LinkedList(node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

// Appending last k nodes
node* appendLastK_nodes(node* &head , int k){
    node* newTail;
    node* newHead;
    node* tail = head;
    int count = 1;
    int len = length_of_LinkedList(head);                   // length of linked list
    k%=len;                                                 // if k is greater then length of linked list
    if(len<k)
        return NULL;
    while(tail->next != NULL){
        if(count==len-k)                                  
            newTail = tail;
        if(count==len-k+1)                                      
            newHead = tail;
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}


// Function to create intersecting linked list
void createIntersectingLinkedList(node* &head,node* head0,int pos){
    node* temp = head;
    pos--;
    while(pos--){
        temp=temp->next;
    }
    node* temp0 = head0;
    while(temp0->next!=NULL){
        temp0=temp0->next;
    }
    temp0->next = temp;
}


// Function to find intersection value
int intersectionNodeValue(node* &head,node* &head0){
    int l1 = length_of_LinkedList(head);
    int l2 = length_of_LinkedList(head0);
    node* ptr1;
    node* ptr2;
    int d=0;
    if(l1>l2){
        d=l1-l2;
        ptr1=head;
        ptr2=head0;
    }else{
        d=l2-l1;
        ptr1=head0;
        ptr2=head;
    }
    // cout<<ptr1->data<<" "<<ptr2->data<<endl;
    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL)
            return -1;
        d--;
    }
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1==ptr2)
            return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}


// Function for Displaying linked list 
void displayLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    node* head = NULL;
    
	cout<<"Initially linked list at starting "<<endl;
	displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Insertion in linked list at tail i.e. at end "<<endl;
	for(int i=0;i<6;i++)
	    insertionAtTail(head,(rand()%10)+1);
	displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Insertion in linked list at head i.e. at start "<<endl;
	for(int i=0;i<2;i++)
	    insertionAtHead(head,(rand()%10)+1);
	displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Searching in a linked list"<<endl;
	for(int i=0;i<2;i++)
	    cout<<boolalpha<<searchingInLinkedList(head,(rand()%10)+1)<<endl;
	cout<<endl<<endl;
	
	cout<<"Deletion at head in a linked list"<<endl;
	deletionAtHead(head);
    displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Deletion of a node in a linked list"<<endl;
	deletion(head,4);
	deletion(head,7);
    displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Reversing a linked list (Iterator method)"<<endl;
	reversingLinkedListIteratorMethod(head);
	displayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Reversing a linked list (Recursive method)"<<endl;
	node* reversedLinkedList = reversingLinkedListRecursiveMethod(head);
	displayLinkedList(reversedLinkedList);
	head = reversedLinkedList;
	cout<<endl<<endl;
	
	cout<<"Reversing k-nodes in a linked list"<<endl;
	node* reversed_k_nodes = reverse_K_Nodes(head,2);
	displayLinkedList(reversed_k_nodes);
	head = reversed_k_nodes;
	cout<<endl<<endl;
	
	cout<<"Appending last k-nodes at starting in a linked list"<<endl;
	node* appendedLinkedList = appendLastK_nodes(head,3);
	displayLinkedList(appendedLinkedList);
	head = appendedLinkedList;
	cout<<endl<<endl;
	
	cout<<"Node data where the two linked list head and head0 intersect is"<<endl;
	node* head0 = NULL;
	insertionAtTail(head0,3);
	insertionAtTail(head0,1);
	insertionAtTail(head0,6);
    cout<<"Linked List 1 : ";
    displayLinkedList(head);
    cout<<"Linked List 2 : ";
    displayLinkedList(head0);
    createIntersectingLinkedList(head,head0,3);
    cout<<"ans = "<<intersectionNodeValue(head,head0)<<endl;
    cout<<endl<<endl;
	
	return 0;
}