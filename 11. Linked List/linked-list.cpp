// Here's is a program below implementing linked-list
// Operations performed are inserting, deleting, searching and displaying

#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* link;
}*head;

void deleteNode(struct Node* pPre)
{
    if (head == NULL)
    {
        return;
    }
    if (pPre == NULL)     // Deleting first node
    head = head->link;
    else // Deleting other nodes
    pPre->link = pPre->link->link;
}

void insertNode(struct Node* pPre, int dataIn)
{
    struct Node* pNew = new Node;
    pNew->data = dataIn;
    if (pPre == NULL)      //Adding before first node or to empty list.
    {
        pNew->link = head;
        head = pNew;
    }
    else                 // Adding in middle or at end.
    {
        pNew->link = pPre->link; 
        pPre->link = pNew;
    }
}

struct Node* searchList(int target)    // 0->1->2->3->4  
{
    struct Node* pLoc, * pPre = NULL;
    pLoc = head;
    if (head == NULL) // Empty list 
    {
        return NULL;
    }
    while (pLoc != NULL && target > pLoc->data) 
    {
        pPre = pLoc;
        pLoc = pLoc->link; 
    }
    return pPre;
}

struct Node* locateList(int target)
{
    struct Node* pLoc, * pPre = NULL;
    pLoc = head;
    while (pLoc != NULL && target != pLoc->data)
    {
        pPre = pLoc;
        pLoc = pLoc->link;
    }
    return pPre;
}

void displayList()
{
    struct Node* pLoc = head;
    while (pLoc != NULL)
    {
        cout << pLoc->data << "\t";
        pLoc = pLoc->link;
    }
}

int main()
{
    struct Node* pPre = NULL;
    head = NULL;
    int data, choice = 1;
    do
    {
        cout << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
switch (choice)
{
    case 1:
        cout << "Enter the value to be inserted to new node: ";
            cin >> data;
        pPre = searchList(data);
        insertNode(pPre, data);
        break;
    case 2:
        cout << "Enter the value to be deleted: ";
        cin >> data;
        pPre = locateList(data);
        deleteNode(pPre);
        cout << data << " deleted" << endl;
        break;
    case 3:
        displayList();
        break;
    
}
} while (choice != 4);
}
