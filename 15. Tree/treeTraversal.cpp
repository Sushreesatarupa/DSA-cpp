#include <iostream>
#include <queue>
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
    void insertNodeBST(Node *&root, int data)
    {
        if (!root)
            root = new Node(data);
        else if (data <= root->data)
            insertNodeBST(root->left, data);
        else
            insertNodeBST(root->right, data);
    }
    void performLevelOrderTraversal(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            q.pop();
        }
        cout << endl;
    }
    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node *root)
    {
        if (!root)
            return;
        preorder(root->left);
        cout << root->data << " ";
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (!root)
            return;
        preorder(root->left);
        preorder(root->right);
        cout << root->data << " ";
    }
public:
    void insert(int data)
    {
        insertNodeBST(root, data);
    }
    void levelOrderTraversal()
    {
        cout << "Level order : ";
        performLevelOrderTraversal(root);
    }
    void depthFirstTraversal()
    {
        cout << "Preorder : ";
        preorder(root);
        cout << endl;
        cout << "Inorder : ";
        inorder(root);
        cout << endl;
        cout << "Postorder : ";
        postorder(root);
        cout << endl;
    }
    
};
int main()
{
    BST t;
    t.insert(5);
    t.insert(3);
    t.insert(8);
    t.insert(2);
    t.levelOrderTraversal();
    t.depthFirstTraversal();
    return 0;
}
