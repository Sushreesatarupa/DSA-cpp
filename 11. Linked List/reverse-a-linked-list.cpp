#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

node *first = NULL;

void create_ll(int A[],int n)
{
   first=new node;
   first->data=A[0];
   first->next=NULL;
   node *last=first;

   for(int i=1;i<n;i++)
   {
      node *ptr=new node;
      ptr->data=A[i];
      ptr->next=NULL;

      last->next=ptr;
      last=ptr;
   }    
}

void display(node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
}

void reverse_by_copy_array(node *ptr)
{
    vector<int> v;
    while(ptr)
    { 
        v.push_back(ptr->data);
        ptr=ptr->next;
    }
    ptr=first;
    int i=v.size()-1;
    while(ptr)
    {
        ptr->data=v[i];
        ptr=ptr->next;
        i--;
    }
}

void ReverseWithoutUsingExtraSpace(node *front)
{
    node *mid=NULL;
    node *last=NULL;

    while(front)
    {
        last=mid;
        mid=front;
        front=front->next;

        mid->next=last;
    }
    first=mid;
}

void ReverseByRecursion(node *tail,node *head)
{
    if(head)
    {
        ReverseByRecursion(head,head->next);
        head->next=tail;
    }
    else
    {
    first=tail;
    }
}

void revrse(node *back, node *forward)
{

    if(forward)
    {
        revrse(forward,forward->next);
        forward->next=back;
    }
    else
    {
        first=back;
    }
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(a)/sizeof(a[0]);

    create_ll(a,size);
    display(first);

    //reverse_by_copy_array(first);
    //ReverseWithoutUsingExtraSpace(first);
    // ReverseByRecursion(NULL,first);
    //first=
    revrse(NULL,first);
    display(first);
}
