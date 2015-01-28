/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

////////////////////////////////////////////////////////////////////////////////////////

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
    void searchNode(TreeNode *node, vector<int> & vec) {
        if ( !node ) return;
        searchNode ( node->left, vec );
        vec.push_back( node->val );
        searchNode ( node->right, vec );
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        searchNode(root, r);
        return r;
    }
};
