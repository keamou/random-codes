/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

///////////////////////////////////////////////////////////////////////////////////////

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
    int search ( TreeNode *node, int &sum ) {
        if ( !node ) return 0;
        int left = search ( node->left, sum );
        int right = search( node->right,sum );
        if ( left < 0 ) left = 0;
        if ( right <0 ) right = 0;
        if ( sum == INT_MIN || left + right + node->val > sum ) {
            sum = left + right + node->val;
        }
        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode *root) {
        int sum = INT_MIN;
        search(root, sum);
        return sum;
    }
};
