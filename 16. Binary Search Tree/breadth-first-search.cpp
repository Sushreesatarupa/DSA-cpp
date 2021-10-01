#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Treenode{
    int data;
    Treenode* left;
    Treenode* right;
    Treenode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void levelOrder(Treenode* root){
    vector<vector<int>> lot;
    if(root==NULL){
        cout<<"";
    }
    queue<Treenode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Treenode *node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        lot.push_back(level);
    }
    for(int i=0;i<lot.size();i++){
        for(int j=0;j<lot[i].size();j++){
            cout<<lot[i][j]<<" ";
        }
    }
}
int main(){
    Treenode* root=new Treenode(1);
    root->left=new Treenode(2);
    root->right=new Treenode(3);
    root->left->left=new Treenode(4);
    root->left->right=new Treenode(5);
    root->right->left=new Treenode(6);
    root->right->right=new Treenode(7);
    levelOrder(root);
}
