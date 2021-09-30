#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node node;

//Basic Structure of each tree node
struct node{

    node* lchild;
    int data;
    node* rchild;
};

//Utility function for allocating memory to each node
node* new_node(int val){
    node* n = (node*)(malloc(sizeof(node)));

    n->data=val;
    n->rchild=n->lchild=NULL;

    return n;
}


//Utility function to insert nodes into tree for initialising a Binary Search Tree
node* insert(node* root, int val){

    if (root==NULL){
        return new_node(val);
    }

    else if (val<root->data){
        root->lchild= insert(root->lchild, val);
    }

    else {
        root->rchild=insert(root->rchild, val);
    }

    return root;
}


//Utility function to print the inorder traversal of the Binary Search Tree
void inorder(node* root){

    if (root->lchild!=NULL){
        inorder(root->lchild);
    }

    printf("%d\t", root->data);

    if (root->rchild!=NULL){
        inorder(root->rchild);
    }
}

//Function to invert a binary tree (also called as mirroring of a binary tree)
void invert_BST(node* root){

    //if the node is NULL, there is nothing to invert
    if (root==NULL){
        return;
    }

    invert_BST(root->lchild);   //recursive call to invert the left subtree
    invert_BST(root->rchild);   //recursive call to invert the right subtree

    //We have performed a BFS and now the actual inversion will be performed

    //swapping the left child pointer and right child pointer
    node* temp = root->lchild;

    root->lchild = root->rchild;

    root->rchild = temp;

}

int main(void){

    node* root = NULL;  //main root of the Binary Search Tree

    //inserting keys
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 13);

    //To show the inorder traversal of the Binary Search Tree that we created
    cout<<"The inorder traversal of tree before inverting:\n";
    inorder(root);
    cout<<"\n\n";

    //Calling the inverting function
    invert_BST(root);

    //To show the inorder traversal of the Binary Search Tree after inverting it
    cout<<"The inorder traversal of tree after inverting:\n";
    inorder(root);
    cout<<'\n';

    // *NOTICE THAT THE INORDER TRAVERSAL OF THE BINARY SEARCH TREE AFTER INVERTING IS EXACTLY THE REVERSE OF THE TRAVERSAL BEFORE INVERTING* //

    return 0;
}
