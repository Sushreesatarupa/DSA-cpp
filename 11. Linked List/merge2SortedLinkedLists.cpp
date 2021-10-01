#include<bits/stdc++.h>
using namespace std;

// Node class for creating nodes of the linkedlist
class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

// utility function to print the linked list
void print(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

// utility function to insert in the front of the linked list
void insertionAtFront(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}
	node* n=new node(d);
	n->next=head;
	head=n;
}


// recursive function to merge the lists
// it returns the head of the new list obtained
node* merge(node* headA,node* headB)
{
	if(headA==NULL)
	{
		return headB;
	}
	else if(headB==NULL)
	{
		return headA;
	}

	else
	{
		node* nhead=NULL;
		if(headA->data<headB->data)
		{
			nhead=headA;
			nhead->next=merge(headA->next,headB);
		}
		else
		{
			nhead=headB;
			nhead->next=merge(headA,headB->next);
		}
		return nhead;
	}
}



// Driver code
int main(){
    node* headA=NULL;
	node* tailA=NULL;
	node* headB=NULL;
	node* tailB=NULL;


	insertionAtFront(headA,tailA,34);
	insertionAtFront(headA,tailA,25);
	insertionAtFront(headA,tailA,11);

    insertionAtFront(headB,tailB,100);
	insertionAtFront(headB,tailB,24);
	insertionAtFront(headB,tailB,10);

    cout<< "Linked List A "<<endl;
    print(headA);
    cout<< endl;
    cout<< "Linked List B "<<endl;
    print(headB);
    cout<< endl;

    node* mergedHead = merge(headA,headB);
    cout<< "Merged Linked List "<< endl;
    print(mergedHead);
    cout<< endl;

    return 0;

}