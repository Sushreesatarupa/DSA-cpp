#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
};
Node *head=NULL;

void insert_beginning()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Node *ptr=new Node();
    ptr->data=n;
    if(head==NULL)
    {
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
        return;
    }
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
}

void insert_middle()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Node *ptr=new Node();
    ptr->data=n;
    if(head==NULL)
    {
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
    }
    else
    {
        int position;
        cout<<"Enter the position: ";
        cin>>position;
        Node *temp=head;
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
    }
}

void insert_end()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Node *ptr=new Node();
    ptr->data=n;
    if(head==NULL)
    {
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
    }
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=NULL;
    }
}

void delete_beginning()
{
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return;
    }
    Node *temp=head;
    cout<<temp->data<<" is deleted!!!"<<endl;
    head=temp->next;
    free(temp);
    free(temp->prev);
    temp->prev=NULL;
}

void delete_middle()
{
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return;
    }
    int position;
    cout<<"Enter the position to delete: ";
    cin>>position;
    Node *temp=head,*next_node;
    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    next_node=temp->next;
    cout<<next_node->data<<" is deleted from "<<position<<endl;
    temp->next=next_node->next;
    next_node->next->prev=temp;
    free(next_node);
}

void delete_end()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return;
    }
    else if(temp->next==NULL)
    {
        cout<<temp->data<<" is deleted!!!"<<endl;
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        cout<<temp->data<<" is deleted!!!"<<endl;
        temp->prev->next=NULL;
        free(temp);
    }
}

void search()
{
    int n,position=1;
    cout<<"Enter the element to be searched: ";
    cin>>n;
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return;
    }
    Node *temp=head;
    while(temp!=NULL)
        {
            if(temp->data==n)
            {
                cout<<n<<" is found at position "<<position<<endl;
                return;
            }
            temp=temp->next;
            position++;
        }
    cout<<"The element was not found!!!"<<endl;
}

void display()
{
    if(head==NULL)
        cout<<"List is empty!!!"<<endl;
    else
    {
        Node *temp=head;
        cout<<"List is: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}

int main()
{
    insert_beginning();
    insert_middle();
    insert_end();
    delete_beginning();
    delete_middle();
    delete_end();
    search();
    display();
    return 0;
}
