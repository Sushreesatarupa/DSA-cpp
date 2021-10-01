#include <iostream>
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
using namespace std;

Node *takeinput()
{

    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

void midpoint(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;
 
    
    if (head != NULL)
    {
        while (fast != NULL&& fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;

          
        }
          cout << "The middle element is [" << slow->data << "]" << endl;
    }
  
}

int main()
{
    Node *head = takeinput();
    print(head);

     midpoint(head);

}