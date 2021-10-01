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
    cout<<"Enter the root data : ";
    int rootData;
    cin>>rootData;
    if(rootData==-1)
    return NULL;
    TreeNode *root=new TreeNode(rootData);

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
            TreeNode *leftChild=new TreeNode(leftChildData);
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

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(todo.empty()!=true)
    {
        auto p=todo.front();
        todo.pop();
        TreeNode* node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left!=NULL)
        todo.push({node->left,{x-1,y+1}});
        if(node->right!=NULL)
        todo.push({node->right,{x+1,y+1}});
    }

    vector<vector<int>> ans;
    for(auto p:nodes)
    {
        vector<int> col;
        for(auto q:p.second)
        {
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    TreeNode* root=inputTree();
    vector<vector<int>> ans=verticalTraversal(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
