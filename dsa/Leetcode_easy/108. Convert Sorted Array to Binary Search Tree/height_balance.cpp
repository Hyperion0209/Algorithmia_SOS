#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* ArrayToBST(TreeNode* root, vector<int>& nums, int start_ind, int size)
{
    if (size == 0)
    {
        return NULL;
    }
    root = new TreeNode(nums[start_ind+(size/2)]);
    int l_ind = start_ind, l_siz = size/2;
    root->left = ArrayToBST(root->left, nums, l_ind, l_siz);
    int r_ind, r_siz;
    if (size%2 == 0)
    {
        r_ind = start_ind + (size/2) + 1;
        r_siz =  (size/2) - 1;
        
    }
    else
    {
        r_ind = start_ind + (size/2) + 1;
        r_siz =  (size/2);
    }
    root->right = ArrayToBST(root->right, nums, r_ind, r_siz);
    return root;
}


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        return ArrayToBST(root, nums, 0, nums.size());
    }
};






//WRONG SOLUTION//
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* Insert(TreeNode* root, int data){
    if (root == NULL)
    {
        root = new TreeNode(data);
    }

    else if (root->val<= data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        TreeNode* root = NULL;
        int mid = size/2;
        for (int i = 0; i<=mid; i++)
        {
            if (i == 0)
            {
                Insert(root, nums[mid]);
            }
            else
            {
                Insert(root, nums[mid-i]);
                if (mid+i<size)
                {
                    Insert(root, nums[mid+i]);
                }
                
            }
        }
        return root;
    }
};