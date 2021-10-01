#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int main()
{
    struct node *root = new node(6);
    root->right = new node(8);
    root->left = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(5);
    root->right->left = new node(7);
    root->right->right = new node(9);

    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return 0;
    }

    queue<node *> q;
    vector<int> traversalData;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        traversalData.push_back(current->data);

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }

    for (int i = 0; i < traversalData.size(); ++i)
    {
        cout << traversalData[i] << " ";
    }
    cout << endl;
    return 0;
}
