/* Question:
    Given a linked list of N nodes such that it may contain a loop.

    A loop here means that the last node of the link list is connected to the node at position X.
    If the link list does not have any loop, X=0.

    Remove the loop from the linked list, if it is present.

    Example 1:

    Input:
    N = 3
    value[] = {1,3,4}
    X = 2
    Output: 1
    Explanation: The link list looks like
    1 -> 3 -> 4
         ^    |
         |____|
    A loop is present. If you remove it
    successfully, the answer will be 1.


    Example 2:

    Input:
    N = 4
    value[] = {1,8,3,4}
    X = 0
    Output: 1
    Explanation: The Linked list does not
    contains any loop.



    Example 3:

    Input:
    N = 4
    value[] = {1,2,3,4}
    X = 1
    Output: 1
    Explanation: The link list looks like
    1 -> 2 -> 3 -> 4
    |______________|
    A loop is present.
    If you remove it successfully,
    the answer will be 1.
*/

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node* p1=head;
    Node* p2=head;
    //Node* t;
    while(p2!=NULL && p2->next!=NULL)
    {
        p2=p2->next->next;
        p1=p1->next;
        if(p1==p2)
        {
            p2=head;
            if(p1!=head)
            {
                while((p2->next) != (p1->next))
                {
                    p2=p2->next;
                    p1=p1->next;
                }

            }
            else
            {
                while(p1->next!=p2)
                p1=p1->next;
            }
            p1->next=NULL;
            break;
        }
    }
}

int main()
{
    int n, num;
    cout<<"Enter the no. of node in the linked list"<<endl;
    cin>>n;

    Node *head, *tail;
    cout<<"Enter the value of the head of the list"<<endl;
    cin>> num;
    head = tail = new Node(num);

    cout<<"Enter values for subsequent nodes"<<endl;
    for(int i=0 ; i<n-1 ; i++)
    {
        cin>> num;
        tail->next = new Node(num);
        tail = tail->next;
    }

    int pos;
    cout<<"Enter position where loop is present"<<endl;
    cin>> pos;
    loopHere(head,tail,pos);

    removeLoop(head);

    if( isLoop(head) || length(head)!=n )
        cout<<"Loop was not removed";
    else
        cout<<"Loop Removed Successfully";

	return 0;
}
