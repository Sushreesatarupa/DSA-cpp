#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

struct queue{
    struct node *front,*rear;
    
    queue(){
        front=rear=NULL;
    }

    void enqueue(int d)
    {
        node* temp=new node(d);
        if(front==NULL)
        {
            rear=front=temp;
            cout<<"\nElement enqueued is : "<<rear->data;
        }

        else{
            rear->next=temp;
            rear=temp;
            cout<<"\nElement enqueued is : "<<rear->data;
        }
    }

    void dequeue(){
        struct node* temp;
        if(front==NULL)
        {
            cout<<"\nQueue is empty (underflow)";
        }

        else{
            temp=front;
            front=front->next;

            if(front==NULL)
            rear==NULL;

            temp->next=NULL;
            cout<<"\nElement dequeued is : "<<temp->data;
            free(temp);
        }
    }

    void display(){
        struct node* temp;
        if(rear==NULL && front==NULL)
        {
            cout<<"\nQueue is empty";
        }

        else{
            cout<<"\nElements in the queue are : ";
                struct node *temp=front;

            while (temp!=NULL)
            {
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
            
            
        }
    }
};

    int main(){
        queue q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.dequeue();
        q.display();

    }