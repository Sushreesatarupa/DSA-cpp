#include<iostream>
using namespace std;

// creating a linked list node with an constructor to initialise a node
class node{
    public:
        int data;
        node* next;
        node(int d){
            data = d;
            next = NULL;
        }
};

//inserting all the nodes at the end of the list to make a clearer observation of rotation
void insertAtEnd(node** head, int d){

    //allocating a new node and starting the constructor
    node* n = new node(d);

    //a node pointer to point the last node in the list
    node* temp = *head;

    //if the list is empty the new node is the head
    if(*head==NULL){
        *head=n;
        return;
    }
    //else traverse the list to find the last node and point to it
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    //changing the next of the last node to point to the new node
    temp->next=n;
    return;
}

void printList(node* head){
    //traversing while the current pointer is not at NULL
    while(head!=NULL){
        //printing the data of the current pointer in the list
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}

void rotateList(node** head, int k){
    //if k=0 the list is not rotated and remains the same
    if(k==0){return;}

    //temporary pointer to iterate the list
    node* temp = *head;

    //count of the current node
    int count = 1;

    //while the count is less than k and the pointer doesn't point to NULL 
    //traversing the list to find the kth node
    while(count<k&&temp!=NULL){
        temp=temp->next;
        count++;
    }

    // if the kth node is not NULL point the kth to the temp pointer
    if(temp==NULL){return;}
    node* kth = temp;

    //traversing while next to temp is not NULL to find the last node in list
    while(temp->next!=NULL){
        temp=temp->next;
    }

    //marking the next of the last node to point to the head
    temp->next=*head;

    //changing the head to the k+1 th node
    *head=kth->next;

    //pointing the next of kth node to NULL
    kth->next=NULL;
}

int main(){
    node* a=NULL;
    int n;
    cout<<"N = ";
    //taking input of nth node
    cin>>n;
    //taking the value of the n nodes
    cout<<"value[] = ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        //passing the data from temp to the insertAtEnd to insert in the linked list
        insertAtEnd(&a,temp);
    }
    printList(a);
    int k;
    cout<<"k = ";
    //taking the value of k
    cin>>k;
    //passing k and the linked list to the rotateList
    rotateList(&a, k);
    //printing result
    printList(a);
    return 0;
}