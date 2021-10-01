# What are Trees?

Tree is a non-Linear Data Structure which contain many nodes where one node is the root of the tree and other nodes are children of the root node.
In general, a node can have any number of children it can have only one parent.
Have a look at the picture below:

![Tree Diagram](https://1.bp.blogspot.com/-9puzUDRgxzg/XkjfzfnrgiI/AAAAAAAAAdY/0Uar4Fk27DE2Y-RxIn5zVvaAnJ2qg_3swCLcBGAsYHQ/s400/structure-of-tree.jpeg)

In the above picture,
A is the root node having B and C as its child.
B is the parent of D E and F.
C is the parent of G.


## Basic Tree Terminology

1. **Root** : Root is a node which does not have a parent. e.g: in the above picture A is the root node.
2. **Parent Node** : Immediate Predecessor of a node. e.g: in the above picture A,B,C,E are parent nodes.
3. **Child Node** : Immediate Successor of a node. e.g: in the above picture B and C are child of A.
4. **Siblings** : Nodes which have same parent. e.g: in the above picture B and C are siblings because they have same parent A.
5. **Height of Tree** : Height of  tree represents the height of its root node (calculated from bottom to top).
6. **Depth of Tree** : Depth of tree is same as Height of Tree however it is calculated from top to bottom).

![Difference between Height and Depth in a Tree](https://1.bp.blogspot.com/-8ePcbTs2ruY/Xkjj3GUe7tI/AAAAAAAAAdk/Jvpvi-TI6ZYQtqGa9ak3WY9POzOrx_jowCEwYBhgL/s320/8yPi9.png "Difference between Height and Depth in a Tree")

7. **Height of Node** : It is the Height from given node to the last possible leaf node.
8. **Depth of Node** : Depth of a node is calculated from traversal from root to a given node. 




## Binary Trees

A Tree whose nodes have at-most 2 children is called a Binary Tree. We name the nodes of a bianary tree from left to right.

![Binary Tree](https://1.bp.blogspot.com/-VlgHtVzjVC8/Xkjkf27-VqI/AAAAAAAAAds/68YZqy3qEigecdK052YTKrGLQZ6tAVihACLcBGAsYHQ/s640/introduction-to-binary-trees-1.png "Binary Tree")



## Types of Binary Trees

**Full Binary Tree** 
 1. A full binary tree has 0 _or_ 2 children. 
 2. In full Binary tree number of leaf nodes are calculated by : L=I+1 (L =number of leaf nodes  ,  I =Number of internal nodes).

![Full Binary Tree](https://1.bp.blogspot.com/-3PS-ONW7RGk/XkjlqfpaTjI/AAAAAAAAAd4/2tu9JqCScdou6QHkHmB89BOXRtG6nJQkQCLcBGAsYHQ/s320/introduction-to-binary-trees-3.png "Full Binary Tree")

**Complete Binary Tree**
If you can fill an array (size of array is no of nodes in tree) by extracting values from tree in left to right fashion such that no index location in array is left empty ,then it is known as a Complete Binary tree. 

![Complete Binary Tree](https://1.bp.blogspot.com/-bVt4ZwfagX8/XkjmaHIrCTI/AAAAAAAAAeA/2uYXv0rT_JEEJE25orBonthCeGCQEvtgACLcBGAsYHQ/s400/introduction-to-binary-trees-5.png "Complete Binary Tree")

**Perfect Binary Tree**
  1. A tree in which every internal node has 2 children and all leaves are at same level.
  2. A perfect Binary tree of height 'h' has 2^h-1 nodes.

![Perfect Binary Tree](https://1.bp.blogspot.com/-3-oBArxcfhw/XkjnIYErzDI/AAAAAAAAAeM/aVH7szpdnholUz4uNzQUjLzrSZX_rm8TQCLcBGAsYHQ/s400/introduction-to-binary-trees-4.png "Perfect Binary Tree")


**Balanced Binary Tree**

A tree is called a balanced binary tree if :
 1. The left and right sub-tree's height differ by at most one.
 2. The left sub-tree is balanced .
 3. The right sub-tree is balanced.

 ![Balanced Binary Tree](https://1.bp.blogspot.com/-v-rdZBgk8mY/XkjnpRoFhDI/AAAAAAAAAeU/yTx8TT8YmEM6IBZ6bWg7EKHZkzFweiumQCLcBGAsYHQ/s640/introduction-to-binary-trees-6.png "Balanced Binary Tree")

**Degenarate Tree**

A tree in which each parent node has only one child node.

![Degenarate Tree](https://1.bp.blogspot.com/-XYiUA9Qt7vI/XkjoAvSVbbI/AAAAAAAAAec/Gk6ydeD9S6wCRpY57pDIN9DhjRmGg7OXQCLcBGAsYHQ/s320/introduction-to-binary-trees-7.png "Degenarate Tree")

## Advantages of trees
1. Trees can be used to represent structural relationship in the data.
2. Trees provide an efficient insertion and searching mechanism.
3. Trees are very flexible and they allow to move sub-trees around with minimum effort.