#include <iostream>
#define n 10
using namespace std;
class Queue
{
    int arr[n];
    int front = -1, rear = -1;
public:
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (((rear + 1) % n) == front);
    }
    void enqueue(int data)
    {
        if (isFull())
            exit(1);
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % n;
        arr[rear] = data;
    }
    void dequeue()
    {
        if (isEmpty())
            exit(2);
        else if (front == rear)
            rear = front = -1;
        else
            front = (front + 1) % n;
    }
    int peek()
    {
        if (front == -1)
            exit(3);
        return arr[front];
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
