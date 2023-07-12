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
    int findMinBST(Node *root)
    {
        if (!root)
            exit(1);
        else if (root->left == nullptr)
            return root->data;
        else
            return findMinBST(root->left);
    }
    int findMaxBST(Node *root)
    {
        if (!root)
            exit(1);
        else if (root->right == nullptr)
            return root->data;
        else
            return findMaxBST(root->right);
    }
public:
    void insert(int data)
    {
        insertNode(root, data);
    }
    int findMin()
    {
        return findMinBST(root);
    }
    int findMax()
    {
        return findMaxBST(root);
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
    cout << t.findMin() << " " << t.findMax();
    return 0;
}
