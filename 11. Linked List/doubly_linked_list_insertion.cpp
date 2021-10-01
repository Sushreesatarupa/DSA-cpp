#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* pre,*next;
}*head=NULL,*temp;
int main(){
    int ch,n;
    cout<<"enter your choice\n";
    cin>>ch;
    while(ch)
    {
        cout<<"enter element to be inserted\n";
        cin>>n;
        node* newnode=new node;
        newnode->data=n;
        newnode->pre=newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->pre=temp;
        }
    cout<<"enter your choice\n";
    cin>>ch;

    }
    temp=head;
    node * p;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        p=temp;
        temp=temp->next;
    }
    do
    {
        cout<<p->data<<" ";
        p=p->pre;
    }while(p!=NULL);

}
