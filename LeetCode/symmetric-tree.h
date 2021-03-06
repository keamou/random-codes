/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

    bool isEqual( TreeNode *left, TreeNode *right ){
        if ( left == NULL && right == NULL ) return true;
        if ( left == NULL && right != NULL ) return false;
        if ( left != NULL && right == NULL ) return false;
        if ( left->val != right->val ) return false;
        if ( !isEqual(left->right, right->left ) ) return false;
        if ( !isEqual(left->left, right->right ) ) return false;
        return true;
    }

    bool isSymmetric(TreeNode *root) {
        if ( root == NULL ) return true;
        return isEqual( root->left, root->right );
    }
};
