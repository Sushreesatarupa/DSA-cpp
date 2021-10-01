#include <stdio.h>
using namespace std;

struct node{
    int data;
    node* next;
};

//Create a new node
struct node* create_node(int x){
    struct node* temp= new node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

//Enter the node into the linked list
void push(node** head,int x){
    struct node* store=create_node(x);
    if(*head==NULL){
        *head =store;
        return;
    }
    struct node* temp=*head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=store;
}

//Delete the middle node from the linked list
void delete_node(node** head){
    if((*head)->next==NULL){
        *head=NULL;
        return;
    }
    struct node* fast=(*head)->next;
    struct node* slow=*head;
    while(fast && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
}

//Print the list
void print(node* head){
	struct node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
    struct node* l=NULL;
    push(&l,1);
    push(&l,2);
    push(&l,3);
    push(&l,4);
    push(&l,5);
    push(&l,6);
    cout<<"Before the delete operation"<<endl;
    print(l);
    delete_node(&l);
    cout<<"\nAfter the delete operation"<<endl;
    print(l);
    return 0;
}
