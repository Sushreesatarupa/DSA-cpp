#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};
class LinkedList
{
    Node *head = nullptr, *tail = nullptr;
    int countNode()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp -> next;
        }
        return count;
    }
public:
    void createDoublyLinkedList(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    void insertAtPosition(int data, int position)
    {
        if (position < 1 || position > countNode())
            exit(1);
        else if (position == 1)
            insertAtBeginning(data);
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            for (int i = 1; i < position - 1; i++)
                temp = temp -> next;
            newNode -> prev = temp;
            newNode -> next = temp -> next;
            temp -> next = newNode;
            newNode -> next -> prev = newNode;
        }
    }
    void deleteFromBeginning()
    {
        Node *temp = head;
        if (!head)
            exit(2);
        head = head -> next;
        head -> prev = nullptr;
        delete temp;
    }
    void deleteFromEnd()
    {
        if (!tail)
            exit(3);
        Node *temp = tail;
        tail -> prev -> next = nullptr;
        tail = tail -> prev;
        delete temp;
    }
    void deleteFromPosition(int position)
    {
        if (position < 1 || position > countNode())
            exit(4);
        if (position == 1)
            deleteFromBeginning();
        else if (position == countNode())
            deleteFromEnd();
        else
        {
            Node *temp = head;
            for (int i = 1; i < position; i++)
                temp = temp -> next;
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
        }
    }
    void reverseList()
    {
        Node *currentNode, *nextNode;
        currentNode = head;
        while (currentNode)
        {
            nextNode = currentNode -> next;
            currentNode -> next = currentNode -> prev;
            currentNode -> prev = nextNode;
            currentNode = nextNode;
        }
        currentNode = head;
        head = tail;
        tail = currentNode;
    }
    void displayList()
    {
        if (!head)
            exit(2);
        Node *temp = head;
        while (temp)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList l1;
    l1.createDoublyLinkedList(3);
    l1.createDoublyLinkedList(4);
    l1.createDoublyLinkedList(5);
    l1.insertAtBeginning(1);
    l1.insertAtPosition(2, 2);
    l1.insertAtEnd(6);
    // l1.deleteFromBeginning();
    // l1.deleteFromEnd();
    // l1.deleteFromPosition(2);
    // l1.deleteFromPosition(1);
    // l1.deleteFromPosition(2);
    // l1.displayList();
    l1.displayList();
    l1.reverseList();
    l1.displayList();
    return 0;
}
