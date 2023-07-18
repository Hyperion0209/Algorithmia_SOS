#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

Node* NewNode(int val)
{
    Node* new_node = new Node;
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* Insert(Node* root, int val)
{
    if (root==NULL)
    {
        root = NewNode(val);
        return root;
    }
    else if (val<= root->data)
    {
        root->left = Insert(root->left, val);
    }
    else
    {
        root->right = Insert(root->right, val);
    }
    return root;
}

Node* Delfunc(Node* root, int val) 
{
    if (root==NULL)
    {
        return root;
    }
    else if (val < root->data)
    {
        root->left = Delfunc(root->left, val);
    }
    else if (val> root->data)
    {
        root->right = Delfunc(root->right, val);
    }
    else
    {
        //CASE 1: 0 child
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        //CASE 2: 1 child
        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //CASE 3: 2 children
        else
        {
            Node* temp = root;
            while(temp->left!=NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delfunc(root->right, root->data);
        }
    }
    return root;
}


int main (){
    Node* root = NULL;
    root = Insert(root, 12);
    root = Insert(root, 15);
    root = Insert(root, 5);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 19);
    root = Delfunc(root, 17);
    cout<< root->right->right->data;


}