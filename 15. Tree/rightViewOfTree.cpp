// Code for right view of tree
#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode *left,*right;
    TreeNode(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

TreeNode* inputTree()
{
    cout<<"Enter the root data: ";
    int rootData;
    cin>>rootData;

    if(rootData==-1)
    return NULL;

    TreeNode* root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.empty()!=true)
    {
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the left child of "<<front->data<<" : ";
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData!=-1)
        {
            TreeNode* leftChild=new TreeNode(leftChildData);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }

        cout<<"Enter the right child of "<<front->data<<" : ";
        int rightChildData;
        cin>>rightChildData;

        if(rightChildData!=-1)
        {
            TreeNode* rightChild=new TreeNode(rightChildData);
            front->right=rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void rightView(TreeNode* root)
{
    if(root==NULL)
    return;

    queue<TreeNode*> q;
    q.push(root);

    while(q.empty()!=true)
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* front=q.front();
            q.pop();

            if(i==size-1)
            cout<<front->data<<" ";

            if(front->left!=NULL)
            q.push(front->left);

            if(front->right!=NULL)
            q.push(front->right);
        }
    }
}

int main()
{
    TreeNode* root=inputTree();
    rightView(root);    
}
