// BST with Dead En
// You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

// Your task is to determine whether the BST contains a dead end.

// Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

// Examples:

// Input: root[] = [8, 5, 9, 2, 7, N, N, 1]
/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool dfs(auto root,int mini,int maxi)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL && mini==maxi)
            return true;
        bool lt=dfs(root->left,mini,root->data-1);
        bool rt=dfs(root->right,root->data+1,maxi);
        return lt||rt;
    }
    bool isDeadEnd(Node *root) 
    {
        return dfs(root,1,INT_MAX);
    }
};