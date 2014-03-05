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
    int maxval ( int a, int b ) {
        if ( a > b ) return a;
        return b;
    }
    int check( TreeNode* node, int& sum ) {
        if ( !node ) return 0;
        int leftsum = 0, rightsum = 0;
        if ( node->left ) leftsum = check( node->left, sum );
        if ( node->right) rightsum= check( node->right, sum);
        int sum1 = leftsum + rightsum + node->val;
        int sum2 = leftsum + node->val;
        int sum3 = rightsum + node->val;
        int sum4 = node->val;
        int tmp = maxval( sum1, maxval( sum2, maxval( sum3, sum4 ) ) );
        if ( tmp > sum ) sum = tmp;
        if ( sum2 > sum3 ) {
            if ( sum2 > sum4 ) {
                return sum2;
            } else {
                return sum4;
            }
        } else {
            if ( sum3 > sum4 ) {
                return sum3;
            } else {
                return sum4;
            }
        }
    }
    
    int maxPathSum(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ( !root ) return 0;
        int sum = root->val;
        int tmp = check( root, sum );
        return sum;
    }
};
