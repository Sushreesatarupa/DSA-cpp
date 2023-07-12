#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
class BST
{
    Node *root = nullptr;
    void insertNode(Node *&root, int data){
        if (!root)
            root = new Node(data);
        else if (data <= root->data)
            insertNode(root->left, data);
        else
            insertNode(root->right, data);
    }
    bool searchNode(Node *root, int data)
    {
        if (!root)
            return false;
        else if (root->data == data)
            return true;
        else if (data <= root->data)
            return searchNode(root->left, data);
        else
            return searchNode(root->right, data);
    }
public:
    void insert(int data)
    {
        insertNode(root, data);
    }
    bool search(int data)
    {
        return searchNode(root, data);
    }
};
int main()
{
    BST t;
    t.insert(15);
    t.insert(10);
    t.insert(20);
    t.insert(25);
    t.insert(8);
    t.insert(12);
    cout << t.search(15) << endl;
    cout << t.search(31) << endl;
    cout << t.search(20) << endl;
    cout << t.search(7) << endl;
    return 0;
}
