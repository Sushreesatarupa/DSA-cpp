// { Driver Code Starts
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

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

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int length(Node * ptr)
{
    int len=0;
    while(ptr)
    {
        len++;
        ptr=ptr->next;
    }
    return len;
}

Node * reset(Node *ptr,int point)
{
    for(int i=0;i<point;i++)
    {
        ptr=ptr->next;
    }
    return ptr;
}

int intersectPoint(Node* head1, Node* head2)
{
    int len1=length(head1);
    int len2=length(head2);
    
    if(len1>len2)
    {
        int mainLen=len1-len2;
        Node *strPtrOfHead1=reset(head1,mainLen);
        Node *strPtrOfHead2=head2;
        
        while(strPtrOfHead1!=strPtrOfHead2)
        {
            strPtrOfHead1=strPtrOfHead1->next;
            strPtrOfHead2=strPtrOfHead2->next;
        }
        
        return strPtrOfHead1->data;
    }
    
    else
    {
        int mainLen=len2-len1;
        Node *strPtrOfHead2=reset(head2,mainLen);
        Node *strPtrOfHead1=head1;
        
        while(strPtrOfHead1!=strPtrOfHead2)
        {
            strPtrOfHead1=strPtrOfHead1->next;
            strPtrOfHead2=strPtrOfHead2->next;
        }
        
        return strPtrOfHead2->data;
    }
}
