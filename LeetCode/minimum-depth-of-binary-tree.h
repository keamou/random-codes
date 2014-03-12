/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

////////////////////////////////////////////////////////////

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

    void depth( TreeNode *node, int & val, int d ) {
        if ( node == NULL ) return;
        if ( val != 0 && val <= d ) return;
        if ( node->left == NULL && node->right == NULL ) {
            if ( val == 0 || val > d ) val = d;
            return;
        }
        depth( node->left, val, d+1 );
        depth( node->right, val, d+1 );
    }
    
    int minDepth(TreeNode *root) {
        int result = 0;
        depth ( root, result, 1 );
        return result;
    }
};
