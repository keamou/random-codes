/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int getDepth( TreeNode *node )
    {
        if ( node->left == NULL && node->right == NULL ) return 1;
        int leftdepth = 0, rightdepth = 0;
        if ( node->left ) {
            int tmp = getDepth( node->left ); 
            if ( tmp == -1 ) return -1;
            leftdepth += tmp;
        }
        if ( node->right ) {
            int tmp = getDepth( node->right );
            if ( tmp == -1 ) return -1;
            rightdepth += tmp;
        }
        if ( abs(leftdepth - rightdepth) > 1 ) return -1;
        return max(leftdepth, rightdepth)+1;
    }
    
    bool isBalanced(TreeNode *root) {
        if ( root == NULL ) return true;
        if ( getDepth(root) == -1 ) return false;
        return true;
    }
};

