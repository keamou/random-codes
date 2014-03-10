/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/


//////////////////////////////////////////////////////////////////////////

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
    void traversal( TreeNode *node, int sum, int &result ) {
        if ( node == NULL ) return;
        sum = sum * 10 + node->val;
        if ( node->left == NULL && node->right == NULL ) {
            result += sum;
            return;
        }
        traversal( node->left, sum, result );
        traversal( node->right, sum, result );
    }
    int sumNumbers(TreeNode *root) {
        int result = 0;
        traversal(root, 0, result);
        return result;
    }
};
