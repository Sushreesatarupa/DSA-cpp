/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum =  INT_MIN;  //initializing sum with minimum value --> -ve infinity
    int findSum(TreeNode* root){
        if(root==NULL)   //checking if root is NULL, if NULL return 0
            return 0;

        int ls = findSum(root->left);    //this is a recursive call, it will give the sum of left nodes of the tree
        int rs = findSum(root->right);  //this is a recursive call, it will give the sum of right nodes of the tree
        ls = max(ls,0);  //storing the maximum of left node sum
        rs = max(rs, 0); //storing the maximum of right node sum
        int cs = ls + rs + root->val;  //storing the current sum for 1 single iteration
        sum = max(sum, cs); //storing the max sum for current sum and sum

        return max(ls, rs) + root->val; //checking and returning the max sum in left node sum and right node sum + the root node sum

    }
    int maxPathSum(TreeNode* root) {  //main function in which root node is given
      findSum(root); //passing root node in findSum function
        return sum;  //returing the result --> maximum path sum
    }
};
