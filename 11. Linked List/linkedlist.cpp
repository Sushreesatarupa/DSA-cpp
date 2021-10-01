#include<bits/stdc++.h>
using namespace std;
//class containing all basic implementation of linked list
class linkedlist{
    struct node
    {
        int data;
        node* next;
    }*head=NULL;
     node * newnode(int data)
    {
        node * temp=new node;
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
   public:
   
    void insert(int data)// inserting at end
    {
        if(head==NULL)
        {
            head=newnode(data);
        }
        else
        {
            node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode(data);
        }
    }
    int count() //counting nodes of linkedlist
    {
        node* temp=head;
        int ans=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            ans++;
        }
        return ans;
    }
    void print() //prints the linked list
    {
        node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->next;
            
        }
        cout<<"NULL"<<endl;
    }
    void reverse() //reverse linked list three pointer method
    {
        node * current=NULL;
        node * previous=NULL;
        node * coming=head;
        current = coming;
        
        while(current!=NULL)
        {
            coming=coming->next;
            current->next=previous;
            previous=current;
            current = coming;
        }
        head=previous;
    }
};

int main()
{
    linkedlist ll;
    ll.insert(12);
    ll.insert(17);
    ll.insert(15);
    cout<<ll.count()<<endl;
    ll.print();
    ll.reverse();
    ll.print();
    ll.reverse();
    ll.print();
    return 0;
}