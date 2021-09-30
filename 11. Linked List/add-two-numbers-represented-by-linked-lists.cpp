#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};


Node *create_ll(Node *head,int A[],int n)
{
    Node *ptr,*last;

    head=new Node;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        ptr=new Node;
        ptr->data=A[i];
        ptr->next=NULL;
        last->next=ptr;
        last=ptr;
    }
    return head;
}

void display(Node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
    cout<<endl;
}

 Node * rev( Node *ptr)
    {
        Node *mid=NULL;
        Node *back=NULL;
        
        while(ptr!=NULL)
        {
            back=mid;
            mid=ptr;
            ptr=ptr->next;
            
            mid->next=back;
        }
        
        return mid;
    }

    Node *NewList(Node *temp,int A[],int len)
    {
       temp=new Node;
       temp->data=A[0];
       temp->next=NULL;
       Node *cur = temp; 
       
       for(int i=1;i<len;i++)
       {
           Node *t=new Node;
           t->data=A[i];
           t->next=NULL;
           cur->next=t;
           cur=t;
       }
       return temp;
    }

    //Function to add two numbers represented by linked list.
     Node* addTwoLists( Node* first,  Node* second)
    {
        Node *ptr=first;
        Node *qtr=second;
             
        ptr=rev(ptr);
        qtr=rev(qtr);

        display(ptr);
        display(qtr);
        
        int A[5000] = {0};
        int length=0;
        
        int result=0;
        int carry=0;
        
        while(ptr && qtr)
        { 
          result = ptr->data + qtr->data + carry;
          
          carry=result/10;
          result%=10;
          A[length]=result;
          
          ptr=ptr->next;
          qtr=qtr->next;
          length++;

        }
    
        while(ptr!=NULL)
        {
            result=ptr->data+carry;
            carry=result/10;
            A[length++]=result%10;
            ptr=ptr->next;
        }
        while(qtr!=NULL)
        {
            result=qtr->data+carry;
            carry=result/10;
            A[length++]=result%10;
            qtr=qtr->next;
        }

        if(carry !=0)
        {
            A[length++]=carry;
        }
        
        Node *head=NULL;
        head=NewList(head,A,length);
        
        display(head);

        head=rev(head);
    return head;
    
}

int main()
{
    int A[]={4,5};
    int B[]={3,4,5};
    
    Node *first=NULL;
    Node *second=NULL;
    
    first=create_ll(first,A,2);
    second=create_ll(second,B,3);   

    cout<<"First"<<" ";
    display(first);
    cout<<"Second"<<" ";
    display(second);
     
    Node *third=NULL; 
    third=addTwoLists(first,second);   
    display(third);

}
