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
    void insertNode(Node *&root, int data)
    {
        if (!root)
            root = new Node(data);
        else if (data <= root->data)
            insertNode(root->left, data);
        else
            insertNode(root->right, data);
    }
    int calculateHeightBST(Node *root)
    {
        if (!root)
            return -1;
        return max(calculateHeightBST(root->left), calculateHeightBST(root->right)) + 1;
    }
public:
    void insert(int data)
    {
        insertNode(root, data);
    }
    int findHeight()
    {
        return calculateHeightBST(root);
    }
};
int main()
{
    BST t;
    t.insert(5);
    t.insert(3);
    t.insert(8);
    t.insert(2);
    cout << t.findHeight();
    return 0;
}
