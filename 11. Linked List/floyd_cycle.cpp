#include <iostream>
using namespace std;

class node{
   public:
  int data;
  node*next;
 node(int d){
      data=d;
      next=NULL;
  }
};
 void insertAtTail(node* &head, int data){
     if(head==NULL){
         head= new node(data);
         return;
     }
     node* temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=new node(data);
     return;
 }
 void buildList(node* &head){
     int data;
     cin>>data;
     while(data!=-1){
         insertAtTail(head,data);
         cin>>data;
     }
     head->next->next->next=head; 
 }

  void print(node* &head){
     node*temp=head;
     while(temp!=NULL){
         cout<<temp->data<<"-->";
         temp=temp->next;
     }
     cout<<endl;
 }

void breakCycle(node* &head,node* &slow,node* &fast){
    node*p=head;
    slow=head;
    node *next=fast->next;
    slow->next=NULL;
    print(slow);
    for(node *temp=next;temp!=slow;temp=temp->next)
    cout<<temp->data<<"-->";
    cout<<endl;
}

bool detectCycle(node* &head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
         fast=fast->next->next;
         slow=slow->next;
         if(slow==fast){
             breakCycle(head,slow,fast);
             return true;
         }
    }
    return false;
}

int main() {

   node* head=NULL;
   cout<<"Enter nodes of tree: "<<endl;
   buildList(head);
   if(detectCycle(head)){
       cout<<"cycle was present in the linked list"<<endl;
       cout<<"if we break the cycle, the linked list becomes : "<<endl;
       print(head);
   }
   else{
       cout<<"No cycle was present"<<endl;
   }


 return 0;
}
