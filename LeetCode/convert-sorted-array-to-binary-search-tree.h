/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

///////////////////////////////////////////////////////////////////////

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

    TreeNode *build( vector<int> &num, int left, int right ) {
        if ( left > right ) return NULL;
        int pivot = (left + right) / 2;
        TreeNode *node = new TreeNode( num[pivot] );
        node->left = build( num, left, pivot-1 );
        node->right = build( num, pivot+1, right );
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build( num, 0, num.size()-1 );
    }
};
