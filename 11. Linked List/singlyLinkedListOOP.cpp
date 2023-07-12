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
    Node *head = nullptr;
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
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
    void insertAtLast(int data)
    {
        if (!head)
            insertAtBeginning(data);
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp -> next)
            temp = temp -> next;
        temp -> next = newNode;
    }
    void insertAtPosition(int data, int position)
    {
        if (position > countNode())
            exit(1);
        Node *newNode = new Node(data);
        Node *temp = head;
        int i = 1;
        while (i < position)
        {
            temp = temp -> next;
            i++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    void deleteFromBeginning()
    {
        if (!head)
            exit(3);
        Node *temp = head;
        head = head -> next;
        delete temp;
    }
    void deleteFromEnd()
    {
        if (!head)
            exit(4);
        Node *temp, *previousNode;
        while (temp -> next)
        {
            previousNode = temp;
            temp = temp -> next;
        }
        if (temp == head)
            head = nullptr;
        else
            previousNode -> next = nullptr;
        delete temp;
    }
    void deleteFromPosition(int position)
    {
        if (!head)
            exit(5);
        Node *nextNode;
        int i = 1;
        Node *temp = head;
        while (i < position - 1)
        {
            temp = temp -> next;
            i++;
        }
        nextNode = temp -> next;
        temp -> next = nextNode -> next;
        delete nextNode;
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
    void reverseList()
    {
        Node *currentNode, *previousNode, *nextNode;
        currentNode = head;
        previousNode = nullptr;
        while (currentNode)
        {
            nextNode = currentNode -> next;
            currentNode -> next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        head = previousNode;
    }
};
int main()
{
    LinkedList l1;
    // l1.insertAtBeginning(2);
    // l1.insertAtBeginning(1);
    // l1.insertAtLast(4);
    // l1.insertAtPosition(3, 2);
    // l1.displayList();
    // l1.deleteFromBeginning();
    // l1.deleteFromPosition(2);
    // l1.deleteFromEnd();
    // l1.displayList();
    // output 2
    
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(3);
    l1.insertAtBeginning(4);
    l1.insertAtBeginning(5);
    l1.displayList();
    l1.reverseList();
    l1.displayList();
    
    
    return 0;
}
