// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
Node *Reverse(Node *up)
{
    Node *mid=NULL;
    Node *back=NULL;
    
    while(up!=NULL)
    {
        back=mid;
        mid=up;
        up=up->next;
        
        mid->next=back;
    }
    return mid;
}

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       Node *fast=head;
       Node *slow=head;
       
       while(fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next;
           if(fast!=NULL)
           {
               fast=fast->next;
           }
       }
      
      slow=Reverse(slow);
      
      Node *temp=head;
      
      while(slow)
      {
        if(temp->data != slow->data)
        {
            return 0;
        }
        temp=temp->next;
        slow=slow->next;
      }
      return 1;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
