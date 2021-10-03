#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

node* head=NULL;

node* insert(node* head,int ele)
{
    node*nnode=new node;
    nnode->data=ele;
    if(head==NULL)
    {
        head=nnode;
        nnode->next=NULL;
    }
    else
    {
        node*temp=head;
        nnode->next=temp;
        head=nnode;
    }
    return head;
}

int middle(node* head)
{
    node*slow=head;
    node*fast=head;    
    if(head==NULL)
    return -1;
    else if(head->next==NULL)
    return head->data;
    else
    {
    while(fast!=NULL&& fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"middle:"<<slow->data<<endl;
    return slow->data;
    }
}

void display(node * head)
{
    node* temp;
    if(head==NULL)
    cout<<"List is Empty"<<endl;
    else
    {
        cout<<"Elements are:";
        temp=head;
        while(temp!=NULL)     
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }   
        cout<<endl;
    }
}
int main()
{
    head=insert(head,30);
    head=insert(head,40);
    head=insert(head,50);
    head=insert(head,60);
    head=insert(head,70);
    head=insert(head,80);
    head=insert(head,90);
    display(head);
    int res=middle(head);
    cout<<"Middle element is:"<<res<<endl;
}