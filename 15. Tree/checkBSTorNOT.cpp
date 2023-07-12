#include <iostream>
#include <climits>
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
    void insertNodeinBST(Node *&root, int data)
    {
        if (!root)
            root = new Node(data);
        else if (data < root->data)
            insertNodeinBST(root->left, data);
        else
            insertNodeinBST(root->right, data);
    }
    bool isBinarySearchTree(Node *root, int minValue, int maxValue)
    {
        if (!root)
            return true;
        if (root->data > minValue && root->data < maxValue && 
            isBinarySearchTree(root->left, minValue, root->data) &&
            isBinarySearchTree(root->right, root->data, maxValue)
        )
            return true;
        return false;
    }
public:
    void insert(int data)
    {
        insertNodeinBST(root, data);
    }
    bool checkValidBST()
    {
        return isBinarySearchTree(root, INT_MIN, INT_MAX);
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
    cout << t.checkValidBST();
    return 0;
}
