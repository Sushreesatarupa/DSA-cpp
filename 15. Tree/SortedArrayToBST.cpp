#include <bits/stdc++.h>
using namespace std;

//Problem link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* bst(int l,int r,vector<int>&nums){
    if (l>r) return nullptr;
        
    int mid = (l+r)/2; //obtaining mid => as root of the tree (rooted here)
    TreeNode* x = new TreeNode(nums[mid]);
    if (l==r) return x;
        
    x->left = bst(l,mid-1,nums); //recur for left and right half to build tree
    x->right = bst(mid+1,r,nums); 
        
    return x;
}
    
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return bst(0,size(nums)-1,nums);
}

int main(){
    int n;cin>>n; //size
    vector<int> nums(n);
    for (auto&x : nums) cin>>x;
      
    TreeNode* T = sortedArrayToBST(nums);
    //print tree
    
  return 0;
  
}
  
