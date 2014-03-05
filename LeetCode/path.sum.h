/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

////////////////////////////////////////////////////////////////////////////////////////////////

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
    bool check( TreeNode *node, int tmp ) {
        tmp = tmp - node->val;
        if ( node->left == NULL && node->right == NULL ) {
            if ( tmp == 0 ) return true;
            return false;
        }
        else {
            if ( node->left ) {
                if( check( node->left, tmp ) ) return true;
            }
            if ( node->right ) {
                if( check( node->right, tmp ) ) return true;
            }
        }
        return false;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ( root == NULL ) return false;
        return check( root, sum );
    }
};
