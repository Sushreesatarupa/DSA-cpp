#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};


// Function to insert value at start of circular linked list
void InsertAtHead(node* &head , int val){
    node* newNode = new node(val);
    if(head==NULL){                                 // No node in head i.e. it is empty or null
        newNode->next = newNode;                             // then head is newNode 
        head = newNode;                        // and newNode's next pointer points to head;
        return;
    }
    node* temp = head;
    while(temp->next!=head){            // Transverse list until we reach at head to insert at starting/ending of list
        temp = temp->next;
    }
    temp->next = newNode;                   // pointing last node to newNode created of new value
    newNode->next = head;                   // Pointing newNode next pointer to head to create circular loop
    head = newNode;                         // Changing head to newNode
}


// Function to insert value at end of circular linked list
void InsertAtTail(node* &head , int val){
    node* newNode = new node(val);
    if(head==NULL){                                 // No node in head i.e. it is empty or null
        newNode->next = newNode;                             // then head is newNode 
        head = newNode;                        // and newNode's next pointer points to head;
        return;
    }
    node* temp = head;
    while(temp->next!=head){                // Transverse list until we reach at head to insert at starting/ending of list
        temp = temp->next;
    }
    temp->next = newNode;               // pointing last node to newNode created of new value
    newNode->next = head;               // Pointing newNode next pointer to head to create circular loop
}


// Function to delete value at head or start in circular linked list
void DeleteAtHead(node* &head){
    if(head==NULL)                  // If head is empty or null then return
        return;
    node* temp = head;
    while(temp->next!=head)             // Transverse until pointer comes back to head to delete first/start node in circular linked list
        temp = temp->next;
    node* todelete = head;                  //Pointer to delete the node which needs to be deleted
    temp->next = head->next;                // Pointer of previous node to the deleting node points to next node of deleting node
    head = head->next;                      // Changing head to next node as head is deleted
    delete todelete;
}


// Function to delete value at a position in circular linked list
void DeleteInLinkedList(node* &head , int pos){
    if(head==NULL)                      // If head is empty or null then return
        return;
    if(pos==1){                             // If position is 1 then we need to delete at hea
        DeleteAtHead(head);
        return;
    }
    int count = 1;
    node* temp = head;
    while(count!=pos-1){                 // Transverse until pointer comes back to position of deleting node in circular linked list
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;        //Pointer to delete the node, which needs to be deleted
    temp->next = temp->next->next;          // Pointer of previous node to the deleting node points to next node of deleting node
    delete todelete;
}



// *******************************************************   Floyds Algorithm  Start ***************************************************************//
// Floyds Algorithms tells that if two pointer meets at some specific and finite index then cycle is present in linked list.
// It is also known as Hare and Tortoise Algorithms


//Function to make linear linked list
void insertionAtTailForLinearLinkedList(node* &head , int val){
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


//Function to make cycle to detect cycle and remove cycle
void makeCycle(node* &head , int pos){
    node* temp = head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos)
            startNode = temp;           // Storing copy of left temp list in startNode to loop it
        temp = temp->next;
        count++;
    }
    temp->next = startNode;             // Pointing last node of temp to startNode to make loop 
}


// Function to detect cycle in circular linked list 
bool DetectCycle(node* &head){
    if(head==NULL)                                  // No node in head means no cycle
        return false;
    if(head->next==head)                            // Only 1 element in head then it has loop always
        return true;
    node* fast = head;                          // Pointer to head which will move faster
    node* slow = head;                          // Pointer to head which will move slower
    while(fast!=NULL and fast->next!=NULL){         // Breaking condition of loop else it will rotate infinitely
        fast = fast->next->next;                    // Increasing fast counter by 2
        slow = slow->next;                          // Increasing slow counter by 1
        if(fast == slow)                        // If both meets at same position then cycle is present
            return true;
    }
    return false;
}


// Function to remove cycle in circular linked list
void RemoveCycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast!=slow);
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}


void displayLinearLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}



// ********************************************************   Floyds Algorithm End  ****************************************************************//



// Function to display circular linked list in single line as circular loop will continue till infinite.
void DisplayLinkedList(node* head){
    node* temp = head;
    if(head==NULL){
        cout<<"NULL"<<endl;
        return;
    }
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"loop"<<endl;
}

int main() {
	node* head = NULL;
	
	cout<<"Circular Linked List at starting"<<endl;
	DisplayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Circular Linked List after adding Nodes at tail"<<endl;
	for(int i=0;i<6;i++)
	    InsertAtTail(head,(rand()%10)+1);
	DisplayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Circular Linked List after adding Nodes at head"<<endl;
	for(int i=0;i<3;i++)
	    InsertAtHead(head,(rand()%10)+1);
	DisplayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Circular Linked List after deleting at head"<<endl;
	DeleteAtHead(head);
	DeleteAtHead(head);
	DisplayLinkedList(head);
	cout<<endl<<endl;
	
	cout<<"Circular Linked List after deleting at position ";
	int pos1 = 2 , pos2 = 5;
	DeleteInLinkedList(head , pos1);
	DeleteInLinkedList(head , pos2);
	cout<<pos1<<" and "<<pos2<<endl;
	DisplayLinkedList(head);
	cout<<endl<<endl;
	
	
	// Complete Floyds Algorithm 
	node* head1 = NULL;
	cout<<"<======== Floyds Algorithm Complete Simulation start ========>"<<endl<<endl<<endl;
	// Inseting some nodes in head1 linked list
	for(int i=0;i<11;i++)
	    insertionAtTailForLinearLinkedList(head1,(rand()%100)+1);
    cout<<"Created linked list before making cycle"<<endl;
    displayLinearLinkedList(head1);
    cout<<"Making cycle in linked list at position ";
    int pos = 5;
    cout<<pos<<" ...."<<endl<<endl;
    makeCycle(head1,pos);
    cout<<"Cycle created in linked list at position "<<pos<<endl<<endl;
    cout<<"Is Cycle present in Linked List? : "<<DetectCycle(head1);
    cout<<endl<<endl;
    cout<<"Removing Cycle in linked list...."<<endl<<endl;
    RemoveCycle(head1);
    cout<<"Cycle Removed From Lineked list"<<endl;
    displayLinearLinkedList(head1);
    cout<<endl<<endl;
    cout<<"Is cycle present in linked list now? : "<<DetectCycle(head1)<<endl<<endl;
    cout<<endl<<endl<<"<======== Floyds Algorithm Complete Simulation end ========>"<<endl<<endl;
	
	return 0;
}
