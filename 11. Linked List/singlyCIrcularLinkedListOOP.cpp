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
class LinkedList
{
    Node *tail = nullptr;
    // void createList(int data) //by maintaining both head and tail pointer
    // {
    //     Node *newNode = new Node(data);
    //     if (!head)
    //         head = tail = newNode;
    //     else
    //     {
    //         tail -> next = newNode;
    //         tail = newNode;
    //     }
    //     tail -> next = head;
    // }
public:
    void createList(int data) //only maintaining a tail pointer
    {
        Node *newNode = new Node(data);
        if (!tail)
        {
            tail = newNode;
            tail -> next = newNode;
        }
        else
        {
            newNode -> next = tail -> next;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void displayList()
    {
        if (!tail)
            exit(1);
        Node *temp = tail -> next;
        while (temp -> next != tail -> next)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << temp -> data << endl;
    }
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (!tail)
            tail = newNode;
        else
            newNode -> next = tail -> next;
        tail -> next = newNode;
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!tail)
        {
            tail = newNode;
            tail -> next = newNode;
        }
        else
        {
            newNode -> next = tail -> next;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void insertAtPosition(int data, int position)
    {
        if (position == 1)
            insertAtBeginning(data);
        else
        {
            Node *newNode = new Node(data);
            Node *temp = tail -> next;
            for (int i = 1; i < position - 1; i++)
                temp = temp -> next;
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
    }
    void deleteFromBeginning()
    {
        if (!tail)
            exit(2);
        Node *temp = tail -> next;
        if (temp -> next == temp)
            tail = nullptr;
        else
            tail -> next = temp -> next;
        delete temp;
    }
    void deleteFromEnd()
    {
        if (!tail)
            exit(3);
        Node *current = tail -> next, *previous;
        if (current -> next == current)
            tail = nullptr;
        else
        {
            while (current -> next != tail -> next)
            {
                previous = current;
                current = current -> next;
            }
            previous -> next = tail -> next;
            tail = previous;
        }
        delete current;
    }
    void deleteFromPosition(int position)
    {
        if (!tail)
            exit(3);
        if (position == 1)
            deleteFromBeginning();
        else
        {
            Node *current = tail -> next, *nextNode;
            for (int i = 1; i < position - 1; i++)
                current = current -> next;
            nextNode = current -> next;
            current -> next = nextNode -> next;
            delete nextNode;
        }
    }
};
int main()
{
    LinkedList l1;
    l1.createList(5);
    l1.createList(6);
    l1.createList(7);
    l1.insertAtBeginning(3);
    l1.insertAtEnd(8);
    l1.insertAtPosition(4, 2);
    l1.deleteFromBeginning();
    l1.deleteFromEnd();
    l1.deleteFromPosition(3);
    l1.displayList();
    return 0;
}
