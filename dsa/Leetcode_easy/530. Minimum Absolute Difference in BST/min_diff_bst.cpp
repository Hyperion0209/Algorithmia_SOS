//https://leetcode.com/problems/minimum-absolute-difference-in-bst/
//530. Minimum Absolute Difference in BST
//Leetcode
//Easy
#include<bits/stdc++.h>
#include<iostream>
#include <cstdlib>
using namespace std;

//WRONG SOLN NO.1 RETURN MAX INSTEAD OF MIN
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int getMaximumDifference(TreeNode* root) {
        //Find left
        TreeNode* temp = root;
        while (temp->left!= nullptr)
        {
            temp = temp->left;
        }
        int left = temp->val;
        temp = root;
        //Find right
        while (temp->right!=nullptr)
        {
            temp = temp->right;
        }
        int right = temp->val;
        //Subtract and mod
        int diff = right - left;
        int abs = abs(diff);
    }
};

//WRONG SOLN NO.2 TOOK DIFFERENCE ONLY BETWEEN NODE AND ITS IMMEDIATE CHILDREN
int findmin(TreeNode* root, int mini)
{
    int som, right_min, left_min, min1;
    if (root == nullptr)
    {
        return mini;
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        return mini;
    }
    

    else if (root->left == nullptr)
    {
        som =  root->right->val-root->val;
        right_min = findmin(root->right, min(som, mini));
        min1 = min(som, right_min);
        mini = min(min1, mini);
    }
    else if (root->right == nullptr)
    {
        som =  root->val-root->left->val;
        left_min = findmin(root->left, min(som, mini));
        min1 = min(som, left_min)
        mini = min(min1, mini);
    }

    else
    {
        som = min(root->val-root->left->val, root->right->val-root->val);
        left_min = findmin(root->left, min(som, mini));
        right_min = findmin(root->right, min(som, mini));
        int lr_min = min(left_min, right_min);
        min1 = min(som, lr_min);
        mini = min(min1, mini);
    }
    return mini;
}
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int mini = min(root->val-root->left->val, root->right->val-root->val);
        int minest = findmin(root, mini);
        return minest;
        //Base Case
        //Actual
        //Next Pass
    }
};


//CORRECT SOLN: TOOK DIFFERENCE BETWEEN INORDER SUCCESSORS 
#include<bits/stdc++.h>
#include<iostream>
#include <cstdlib>
using namespace std;
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
TreeNode* GetSuccessor(TreeNode* current, TreeNode* root_tree)
{
    if (current == NULL)
    {
        return NULL;
    }
    else if(current->right!= NULL)
    {
        TreeNode* temp = current->right;
        while (temp->left!= NULL)
        {
            temp = temp->left;
        }
        return temp; 
    }
    else
    {
        TreeNode* successor = NULL;
        TreeNode* ancestor = root_tree;
        while (ancestor!= current)
        {
            if(current->val<ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
        

    }
}
int InorderMin(TreeNode* root, TreeNode* root_tree)
{
    //int minest;
    TreeNode* successor = GetSuccessor(root, root_tree);
    if (successor == NULL)
    {
        return 1000000; 
    } 
    
    // else if (successor->val-root->val < InorderMin(successor, root_tree))
    // {
    //     minest = successor->val-root->val;
    // }
    // else   TIME LIMIT EXCEEDED ON USING THIS
    // {
    //     minest = InorderMin(successor, root_tree);
    // }
    // return minest;
    else 
    {
        return min(successor->val-root->val, InorderMin(successor, root_tree));
    }
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* temp1 = root;
        while(temp1->left!=NULL)
        {
            temp1 = temp1->left;
        }
        return InorderMin(temp1, root);
    }
};