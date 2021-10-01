// C++ program to find binary tree with given inorder
// traversal
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
 int key;
 struct Node *left, *right;
};

// A utility function to create a new tree Node
struct Node *newNode(int item)
{
 struct Node *temp = new Node;
 temp->key = item;
 temp->left = temp->right = NULL;
 return temp;
}

// A utility function to do preorder traversal of BST
void preorder(Node *root)
{
 if (root != NULL)
 {
	 printf("%d ", root->key);
	 preorder(root->left);
	 preorder(root->right);
 }
}

// Function for constructing all possible trees with
// given inorder traversal stored in an array from
// arr[start] to arr[end]. This function returns a
// vector of trees.
vector<Node *> getTrees(int arr[], int start, int end)
{
 // List to store all possible trees
 vector<Node *> trees;

 /* if start > end then subtree will be empty so
 returning NULL in the list */
 if (start > end)
 {
	 trees.push_back(NULL);
	 return trees;
 }

 /* Iterating through all values from start to end
	 for constructing left and right subtree
	 recursively */
 for (int i = start; i <= end; i++)
 {
	 /* Constructing left subtree */
	 vector<Node *> ltrees = getTrees(arr, start, i-1);

	 /* Constructing right subtree */
	 vector<Node *> rtrees = getTrees(arr, i+1, end);

	 /* Now looping through all left and right subtrees
	 and connecting them to ith root below */
	 for (int j = 0; j < ltrees.size(); j++)
	 {
		 for (int k = 0; k < rtrees.size(); k++)
		 {
			 // Making arr[i] as root
			 Node * node = newNode(arr[i]);

			 // Connecting left subtree
			 node->left = ltrees[j];

			 // Connecting right subtree
			 node->right = rtrees[k];

			 // Adding this tree to list
			 trees.push_back(node);
		 }
	 }
 }
 return trees;
}

// Driver Program to test above functions
int main()
{
 int in[] = {4, 5, 7};
 int n = sizeof(in) / sizeof(in[0]);

 vector<Node *> trees = getTrees(in, 0, n-1);

 cout << "Preorder traversals of different "
		 << "possible Binary Trees are \n";
 for (int i = 0; i < trees.size(); i++)
 {
	 preorder(trees[i]);
	 printf("\n");
 }
 return 0;
}
