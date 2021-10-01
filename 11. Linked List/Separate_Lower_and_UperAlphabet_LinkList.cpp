#include <iostream>
using namespace std;
class node
{
public:
    char data;
    node *next;
    node(char val)
    {
        data = val;
        next = NULL;
    }
};
class node1
{
public:
    char data1;
    node1 *next1;
    node1(char val1)
    {
        data1 = val1;
        next1 = NULL;
    }
};
class node2
{
public:
    char data2;
    node2 *next2;
    node2(char val2)
    {
        data2 = val2;
        next2 = NULL;
    }
};
void insert(node *&head, char val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insert1(node1 *&head1, char val1)
{
    node1 *n = new node1(val1);
    if (head1 == NULL)
    {
        head1 = n;
        return;
    }
    node1 *temp1 = head1;
    while (temp1->next1 != NULL)
    {
        temp1 = temp1->next1;
    }
    temp1->next1 = n;
}
void insert2(node2 *&head2, char val2)
{
    node2 *n = new node2(val2);
    if (head2 == NULL)
    {
        head2 = n;
        return;
    }
    node2 *temp2 = head2;
    while (temp2->next2 != NULL)
    {
        temp2 = temp2->next2;
    }
    temp2->next2 = n;
}
void display1(node1 *head1)
{
    node1 *temp1 = head1;
    while (temp1 != NULL)
    {
        cout << temp1->data1 << " ";
        temp1 = temp1->next1;
    }
    cout << endl;
}
void display2(node2 *head2)
{
    node2 *temp2 = head2;
    while (temp2 != NULL)
    {
        cout << temp2->data2 << " ";
        temp2 = temp2->next2;
    }
    cout << endl;
}
void display(node *head)
{
    node1 *head1 = NULL;
    node2 *head2 = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->data >= 'A' && temp->data <= 'Z')
            insert1(head1, temp->data);
        else if (temp->data >= 'a' && temp->data <= 'z')
            insert2(head2, temp->data);
        temp = temp->next;
    }
    cout << endl;
    cout << "Linked list of Uppercase characters\n";
    display1(head1);
    cout << "Linked list of lowercase characters\n";
    display2(head2);
}
int main()
{
    node *head = NULL;
    insert(head, 'A');
    insert(head, 'b');
    insert(head, 'C');
    insert(head, 'd');
    insert(head, 'E');
    insert(head, 'f');
    insert(head, 'G');
    insert(head, 'h');
    insert(head, 'I');
    insert(head, 'j');
    cout << "Given linked list\n";
    display(head);
}
