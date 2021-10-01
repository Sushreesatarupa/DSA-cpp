# Creating a Binary Search Tree

A **Binary Search Tree** is a Binary Tree in which the left subtree of a node is always smaller and the right subtree of that node is always greater than itself.

![img0](https://www.techiedelight.com/wp-content/uploads/BST.png)



## Steps to Construct a Binary Search Tree

1. Firstly, we will create a structure to define 3 partitions of a node.

```C++
struct bstnode
{
int data;      // in data this part the actual data of the node will be stored.
bstnode* left;  // in left part we will store the address of the left child of that node.
bstnode* right;  // in right part we will store the address of the right child of that node.
}
```

---


2. Now, we will have to create a function that will insert data in the node by determining whether the data in child node greater or less than the data at root node.

---

3. Before, Insertion we need a function to create a node.


```C++
bstnode* getnewnode(int data)
{
bstnode* newnode=new bstnode();
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
```

  - In above function receives a value which is to be inserted in the node.
  - Next, we have created an object of structure bstnode called newnode.
  - Next, since newnode is object of structure bstnode thus it has 3 partitions namely data, left and right.
  - In, the data part of newnode we have inserted the data using arrow operator( -> ).
  - Similarly,we have assigned NULL to left and right part of a node because initially when a node is created it does not have any child to which it should point.
  - At the end we are returning the node to the function which called this getnewnode().

---

4. Now, we can start working on insertion function which will decide whether the data will go to right of the node or left of the node.


```c++
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
```

- The insert function has 2 parameters pointer to root and a data which is to be inserted to the node.
- We have couple of cases for insertion.
- Firstly, the tree maybe empty. If tree is empty i.e root is NULL we can simply create a new node by calling getnewnode() and assign it to the root. See the picture below:
- Initially, root was NULL when insert(0,15) was called . Then we called getnewnode(15) which created a new node having address 200 and returning the address 200 to insert() function back.
Then, root is also returned from insert() to main() to create a link between root and this newly created node.

![img1](https://media.cheggcdn.com/coop/861/86157e75-b75d-4c32-9909-d519d353ea7a/1605939579682_chg1.png)

- Now , let say we have to insert number 10 and we made a call from main to insert like insert(200,10) then at this stage root is 200 (remember in the last point we discussed the root was returned from insert to main().
- Now if the data to be inserted is lesser or equal then we have to insert it in the left subtree otherwise right sub-tree. In this case 10 is to be inserted to the tree which is lesser than root node's data 15, thus we have to insert it in the left sub-tree.
- Hence , look at second condition (else if(root->data>=data)) .Inside this condition we have made a recursive call to insert() again but we call to root->left and and then we assign the address of this node to root's left location.
- While the recursive call is made to insert() then this insert() will call the getnewnode() to create a new node and return the address of this newly created node to previous insert call i.e insert(200,10).


![img2](https://media.cheggcdn.com/coop/d31/d31abfe8-324c-47bb-aad4-d180709bf1b1/1605939602541_chg2.png)

- Similarly,if we have an data greater than root's data then it will be inserted in the right sub-tree which is the 3rd condition.

---

5. You can check if the tree is actually made or not by searching for data in the tree.

```c++
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
```


- If root is NULL then we return false because no tree exists.
- If data is found at root node itself then we return true.
- Otherwise, if data is less root's data then we search left sub-tree.
- Or, if data is greater than root's data we search the right sub-tree.

---

**Below, I have given complete code to implement binary search tree in c++.**

```c++
#include<iostream>
using namespace std;

struct bstnode
{
    int data;
    bstnode* left;
    bstnode* right;
};

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
    int key;
    cout<<"enter a value to be searched: ";
    cin>>key;
    if(searchnode(root,key))
    {
        cout<<"value present in tree";
    }
    else
    {
        cout<<"value not present in tree";
    }
    return 0;
}
```