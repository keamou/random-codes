/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.
*/

//////////////////////////////////////////////////////////////////////

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

    TreeNode *flattenNode ( TreeNode * node ) {
        if ( node == NULL ) return node;
        if ( node->left == NULL ) {
            if ( node->right == NULL ) return node;
            return flattenNode( node->right );
        } else {
            TreeNode *tmp1 = flattenNode( node->left );
            TreeNode *tmp2 = flattenNode( node->right );
            tmp1->right = node->right;
            node->right = node->left;
            node->left = NULL;
            if ( tmp2 != NULL ) return tmp2;
            return tmp1;
        }
    }

    void flatten(TreeNode *root) {
        flattenNode(root);
    }
};
