#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

struct Node* revrse(struct Node *back, struct Node *forward)
{

    if(forward)
    {
        revrse(forward,forward->next);
        forward->next=back;
    }
    else
    {
        start=back;
    }
}

struct Node* reverseList(struct Node *head)
    {
        /* struct Node *back=NULL;
         struct Node *mid=NULL;
         struct Node *front=head;
         
         while(front!=NULL)
         {
             
             back=mid;
             mid=front;
             front=front->next;
             
             mid->next=back;
             
             
         }
         head=mid;
         return head;
         */
         revrse(NULL,head);
         return start;
    }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      start = reverseList(start);
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 
 void display(struct Node *head)
{
   while(head!=NULL)
  {
   printf("%d ",head->data);
    head=head->next;
  }
}



class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
         Node* current = head;
        Node* prev = NULL; Node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
};