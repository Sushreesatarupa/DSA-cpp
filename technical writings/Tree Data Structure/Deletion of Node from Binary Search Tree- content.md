# Deletion of a Node in Binary Search Tree

 Deletion has always been a tricky concept in data structures. In case of trees deletion is a bit complicated but once you read through this article I bet that you will never forget how to delete a node from a binary tree.

 First of all we must know the property of a Binary Tree that values in the left subtree are less than the value at root and values in the right subtree are greater than value at root.

 ![img1](https://1.bp.blogspot.com/-wJ_SNbgt66Y/Xm36LAoxA-I/AAAAAAAAAhk/sDpuEmdLY0Y0YAjhLLhA2p1crXPbjhlvACLcBGAsYHQ/s640/1.png)

 Now when we delete a node from a tree we must make sure that this property of tree is maintained throughout. Before deletion let's think of all the possible scenarios in which deletion of a node can occur.

## Deleting A Leaf Node

Let say we want to delete node with value 19. Then we have to do 2 things in order to delete it.

1. We need to remove reference of node with value 19 with its parent node a.k.a node with value 17.
2. We need to free the memory of the node being deleted.

![img2](https://1.bp.blogspot.com/-RhZ5n6odvZ0/Xm37hRpmdVI/AAAAAAAAAhw/EGff_rB3EGQeFmB3zyZmtgeWHlh8Mxv8wCLcBGAsYHQ/s640/2.png)

The node with value 19 is a leaf node so deleting this node won't affect the basic property of the tree. So, deleting a leaf node is simple since deleting the leaf node does not affect the tree. 

## Deleting the Node with 1 Child

So if a node is being deleted which has 1 child then what logic can be applied so that the property of the tree remain intact?
Let say we want to delete node with value 7 which has only 1 child as shown in picture below, then we can just link the parent of node with value 7 a.k.a node with value 5 with the child of node 7 a.k.a the node with value 9.

![img3](https://1.bp.blogspot.com/-cS7dJROZS_o/Xm39IA1ymzI/AAAAAAAAAh8/mWDLj1NJO44erVyVN_P8wzZTyJDhg1wBACLcBGAsYHQ/s640/3.png)

The basic property of tree is also preserved with this logic. So, our new tree is given below:
![img4](https://1.bp.blogspot.com/-IDpPyP1UOQI/Xm39iGCfNqI/AAAAAAAAAiE/Xzi7WqeciS8g57lc4DnOcBq6sXvNAE7_QCLcBGAsYHQ/s640/4.png)


## Deletion of a Node with 2 children

Consider the node with value 15 which has 2 children 13 and 17 in the picture below. If we connect node with value 12 to node with value 13 directly then we will lose right subtree of 15 or if we connect the node with value 12 to node with value 17 directly then we will lose left subtree.
So,we need to think something different.

![img4](https://1.bp.blogspot.com/-EO-dCZS9tfc/Xm3-h2NQS7I/AAAAAAAAAiQ/5h_fHq7exv8-8zWJJqzfb32AWFIIa6cAwCLcBGAsYHQ/s640/5.png)

So, to delete the node with value 15 we will look into the right subtree of 15 and find the node with minimum value. Then we will replace 15 with that value.
In the right subtree of 15 ,17 is the smallest value thus we will replace 15 with 17 .
But notice that node with value 17 is also having child but that will not bother us anymore because we know how to deal with the node with only one child.

![img5](https://1.bp.blogspot.com/-AoNA5BXfLP0/Xm3_sjsKdWI/AAAAAAAAAic/wjqzNaSrA8EnK-w77v91HjL6t0yibfNjQCLcBGAsYHQ/s640/6.png)

![img6](https://1.bp.blogspot.com/--8sLbJNdkVM/Xm3_3Xsm94I/AAAAAAAAAig/A-VeuvooQngf_TeEvfrvLDvrbt9ZUTEVwCLcBGAsYHQ/s640/7.png)

**_NOTE: There is another approach that we can replace the node being deleted with the maximum value from the left subtree._**

The final tree is:

![img7](https://1.bp.blogspot.com/-MKi40uq1kdI/Xm4AQhpP5cI/AAAAAAAAAis/caEHKbvEdHM9SUHmwjN4Nt2-RfG_U8WFACLcBGAsYHQ/s640/8.png)


## Logic for Deletion of a Node From BST

```c++
Logic for Deletion of a Node

//delete function will a have 2 arguments one the reference to root and second the data which is to be deleted
delete(node* root,int data)
{
        //first we need to locate the node which is to be deleted
        if(root==null)
             return root;
        else if(data < root->data) //if data is less than root than move to left subtree
             root->left=delete(root->left,data);
        else if(data > root->data) //otherwise move to right subtree
             root->right=delete(root->right,data);
        else  //we have reached to the correct node
         {
              //case 1: if it is a leaf node
              if(root->left==null && root->right==null)
              {
                         delete root;
                         root=null;
              }
              //case 2: if a  node has one child
              else if(root->left==null)
             {
                         struct node *temp=root; //store current address of root in temporary pointer to node
                         root=root->right;
                         delete temp;
              }
              else if(root->right==null)
              {
                         struct node *temp=root;
                         root=root->left;
                         delete temp;
              }
              //case 3: if a node has 2 child
              else
              {
                         struct node *temp=findmin(root->right); //to find minimum value in right subtree
                         root->data=temp->data;
                         root->right=delete(root->right,temp->data);
              }
        return root;
}
     
node *findmin(node* root)
{
       while(root->left!=null)
       {
              root=root->left;
       }
  return root;
}   
```

## Implementation in C++

```c++
#include<iostream>
using namespace std;

struct bstnode
{
    int data;
    bstnode* left;
    bstnode* right;
};


bstnode* findmin(bstnode* root)
{
      while(root->left!=NULL)
            root=root->left;
      return root;
}

bstnode* Delete(bstnode* root, int data) 
{

if(root==NULL)
  return root;
else if(data < root->data)  
   root->left=Delete(root->left,data);
else if(data>root->data) 
   root->right=Delete(root->right,data);
else 
{
    //case 1: when node has no child
    if(root->left==NULL && root->right==NULL)
        {
              delete root;
              root=NULL;
              return root;
       }
     //case 2: one child
      else if(root->left==NULL)
      {
             struct bstnode * temp=root;
             root=root->right;
             delete temp;
             return root;
      }
      else if(root->right==NULL)
      {
             struct bstnode * temp=root;
             root=root->left;
             delete temp;
             return root;
      }
      else
      {
              struct bstnode *temp=findmin(root->right);
              root->data=temp->data;
              root->right=Delete(root->right,temp->data);
              return root;
       }
 }
}

bstnode* getnewnode(int data)
{
    bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

bstnode* insert(bstnode* root,int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
    }
    else if(root->data>=data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

bool searchnode(bstnode* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data<=root->data)
        return searchnode(root->left,data);
    else
        return searchnode(root->right,data);
}

int main()
{
    bstnode* root=NULL;
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    cout<<"tree in the memory is as follow:"<<endl;
    cout<<"               15               "<<endl;
    cout<<"              /  \\              "<<endl;
    cout<<"            10    20            "<<endl;
    cout<<"           /  \\    \\           "<<endl;
    cout<<"          8    12   25         "<<endl;
    cout<<endl;
    
    cout<<"Now we will delete node with value 20"<<endl;
    Delete(root,20);
    int key;
    cout<<"enter a value to be searched: ";
    cin>>key;
    if(searchnode(root,20))
    {
        cout<<"20 present in tree!";
    }
    else
    {
        cout<<"20 not present!"<<endl;
        cout<<"which means 20 is deleted from the tree!!";
    }
    return 0;
}




```

## OUTPUT
![img8](https://1.bp.blogspot.com/-wJucKHlTff0/Xm4HpexMiqI/AAAAAAAAAi4/5HbqRmQo_zsL73RC5O239pprCam-xdUwACLcBGAsYHQ/s640/sc.png)