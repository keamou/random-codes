/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/////////////////////////////////////////////////////////////////////////////////////////

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
    int traversal( TreeNode *node, int depth ) {
        int cur_depth = depth;
        if ( node->left ) cur_depth = traversal( node->left, depth+1 );
        if ( node->right) {
            int tmp = traversal( node->right, depth+1);
            if ( tmp > cur_depth ) cur_depth = tmp;
        }
        return cur_depth;
    }
    int maxDepth(TreeNode *root) {
        if ( root == NULL ) return 0;
        return traversal( root, 1 );
    }
};
