//https://leetcode.com/problems/search-in-a-binary-search-tree/description/
//Leet Code Easy
//700. Search in a Binary Search Tree

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
TreeNode* FindNode(TreeNode* root, int val){
    if (root == nullptr)
    {
        return nullptr;
    }
    
    else if (root->val < val)
    {
        return FindNode(root->left, val);
    }
    else if (root->val < val)
    {
        return FindNode(root->right, val);
    }
    else
    {
        return root;
    }
}
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return FindNode(root, val);
    }
};