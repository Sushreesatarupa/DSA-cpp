/* Question:
    Given two singly linked lists of size N and M,
    write a program to get the point where two linked lists intersect each other.

    Example:
    Input:
    Linked List 1 = 4->1->common
    Linked List 2 = 5->6->1->common
    common = 8->4->5->NULL
    Output: 8
    Explanation:

    4              5
    |              |
    1              6
     \             /
      8   -----  1
       |
       4
       |
      5
      |
      NULL
*/
#include<bits/stdc++.h>

using namespace std;

//Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to take Linked List elements as input.

Node* inputList(int size)
{
    if(size==0) return NULL;

    int val;
    cin>> val;

    Node *head = new Node(val);
    Node *tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

//Function to find intersection point in Y shaped Linked Lists.

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* p = head1;
    while(p->next!=NULL)
    {
        p=p->next;

    }
    p->next = head1;
    Node* s = head2;
    Node* f = head2;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
        break;
    }
    if(f==NULL || f->next==NULL)
    return -1;
    s = head2;
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return s->data;

}

int main()
{
    int n1,n2,n3;

    cout<<"Enter No. of elements in list 1"<<endl;
    cin>>n1;
    cout<<"Enter No. of elements in list 2"<<endl;
    cin>>n2;
    cout<<"Enter No. of elements in the common list"<<endl;
    cin>>n3;

    cout<<"Enter elements for first list"<<endl;
    Node* head1 = inputList(n1);
    cout<<"Enter elements for second list"<<endl;
    Node* head2 = inputList(n2);
    cout<<"Enter elements for the common list"<<endl;
    Node* common = inputList(n3);

    Node* temp = head1;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;

    temp = head2;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;

    cout << "intersection point is: "<<intersectPoint(head1, head2) << endl;
    return 0;
}
