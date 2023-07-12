#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};
class Queue
{
    Node *front = nullptr, *rear = nullptr;
public:
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (!front && !rear)
            front = rear = newNode;
        else
        {
            rear -> next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (!front)
            exit(1);
        Node *temp = front;
        if (front == rear)
            front = rear = nullptr;
        else
            front = front -> next;
        delete temp;
    }
    int peek()
    {
        if (!front)
            exit(2);
        return front -> data;
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    cout << q.peek();
    return 0;
}
