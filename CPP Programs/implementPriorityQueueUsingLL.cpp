#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node * front = NULL;
struct Node * rear = NULL;


int isFull(){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int val){

    if(isFull()){
        cout<<"Queue is full can't enqueue"<<endl;
    }else{
        struct Node * n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->next = NULL;

        if(front == NULL){
            front = n;
            rear = n;
        }else if(front->data > n->data){
            n->next = front;
            front = n;
        }else if(rear->data < n->data){
            rear->next = n;
            rear = n;
        }else{
            struct Node * ptr = front;
            struct Node * ptr2 = front->next;

            while(ptr2->data < n->data && ptr2->next!=NULL){
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
            n->next = ptr->next;
            ptr->next = n;
            
        }
    }
}

int dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty can;t dequeue"<<endl;
        return -1;
    }else{
        struct Node * n = front;
        front = front->next;
        int x = n->data;
        free(n);
        return x;
    }
}


void display(struct Node * front){
    while(front!=NULL){
        cout<<front->data<<endl;
        front = front->next;
    }
}

int main(){

    enqueue(5);
    enqueue(2);
    enqueue(1);
    enqueue(2);

    display(front);
    cout<<endl;

    dequeue();

    display(front);
    cout<<endl;

    dequeue();

    display(front);
    cout<<endl;

    enqueue(0);

    
    display(front);
    cout<<endl;


    return 0;
}
