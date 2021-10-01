#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

int main(){
    struct node *root=new node(6);
    root->right=new node(8);
    root->left=new node(4);
    root->left->left=new node(2);
    root->left->right=new node(5);
    root->right->left=new node(7);
    root->right->right=new node(9);
}
