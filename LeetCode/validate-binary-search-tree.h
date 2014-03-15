/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/////////////////////////////////////////////////////////////////

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
    int max( TreeNode *node ) {
        if ( node ) {
            int maxleft = max(node->left);
            int maxright = max(node->right);
            if ( maxleft > maxright ) {
                if ( node->val > maxleft ) return node->val;
                return maxleft;
            } else {
                if ( node->val > maxright ) return node->val;
                return maxright;
            }
            return node->val;
        }
        return INT_MIN;
    }
    
    int min( TreeNode *node ) {
        if ( node ) {
            int minleft = min(node->left);
            int minright = min(node->right);
            if ( minleft < minright ) {
                if ( node->val < minleft ) return node->val;
                return minleft;
            } else {
                if ( node->val < minright ) return node->val;
                return minright;
            }
            return node->val;
        }
        return INT_MAX;
    }

    bool isValidBST(TreeNode *root) {
        if ( root == NULL ) return true;
        if ( root->left ) {
            int maxleft = max(root->left);
            if ( maxleft >= root->val ) return false;
        }
        if ( root->right ) {
            int minright = min(root->right);
            if ( minright <= root->val ) return false;
        }
        if( isValidBST( root->left ) && isValidBST( root->right ) ) return true;
        return false;
    }
};
