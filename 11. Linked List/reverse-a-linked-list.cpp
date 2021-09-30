Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore
 
@Shashwatsingh22 
Shashwatsingh22
/
Practice_Le
Public
1
1
1
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Practice_Le/GfG/LinkedList/reverse_ll.cpp
@Shashwatsingh22
Shashwatsingh22 update
Latest commit 1aacabd on May 3
 History
 1 contributor
114 lines (92 sloc)  1.84 KB
   
// { Driver Code Starts
//Initial Template for C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

 // } Driver Code Ends
//User function Template for C

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

// { Driver Code Starts.

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




  // } Driver Code Ends
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete
