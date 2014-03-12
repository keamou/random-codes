/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

//////////////////////////////////////////////////////////////////////////////

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
    
    void check( TreeNode *node, int tmp, vector<int> & record, vector< vector<int> > & result ) {
        if ( node == NULL ) return;
        tmp = tmp - node->val;
        record.push_back( node->val );
        if ( node->left == NULL && node->right == NULL ) {
            if ( tmp == 0 ) result.push_back( record );
        }
        else {
            check( node->left, tmp, record, result );
            check( node->right, tmp, record, result );
        }
        record.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > result;
        vector<int> record;
        check( root, sum, record, result );
        return result;
    }
};
