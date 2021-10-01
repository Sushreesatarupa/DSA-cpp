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
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    if(rootData==-1)
    return NULL;
    TreeNode* root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
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
int maxDistance(TreeNode* target,map<TreeNode*,TreeNode*>& mp)
{
    map<TreeNode*,int> vis;
    queue<TreeNode*> q;
    q.push(target);
    vis[target]=1;
    int max=0;

    while(q.empty()!=true)
    {
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++)
        {
            TreeNode* front=q.front();
            q.pop();

            if(front->left!=NULL && !vis[front->left])
            {
                flag=1;
                vis[front->left]=1;
                q.push(front->left);
            }

            if(front->right!=NULL && !vis[front->right])
            {
                flag=1;
                vis[front->right]=1;
                q.push(front->right);
            }

            if(mp[front] && !vis[mp[front]])
            {
                flag=1;
                vis[mp[front]]=1;
                q.push(mp[front]);
            }
        }
        if(flag)
        max++;
    }
    return max;
}

TreeNode* bfsMapToParents(TreeNode* root,map<TreeNode*,TreeNode*>& mp,int start)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;

    while(q.empty()!=true)
    {
        TreeNode* front=q.front();
        if(front->data==start)
        res=front;

        q.pop();

        if(front->left!=NULL)
        {
            q.push(front->left);
            mp[front->left]=front;
        }

        if(front->right!=NULL)
        {
            q.push(front->right);
            mp[front->right]=front;
        }
    }
    return res;
}
int timeToBurn(TreeNode* root,int start)
{
    map<TreeNode*,TreeNode*> mp;
    TreeNode* target=bfsMapToParents(root,mp,start);
    int time=maxDistance(target,mp);
    return time;
}

int main()
{
    TreeNode* root=inputTree();
    int start;
    cin>>start;
    cout<<"Time to burn the tree from "<<start<<" = "<<timeToBurn(root,start)<<"\n";


}
