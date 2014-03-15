/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

///////////////////////////////////////////////////////////////////////////

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
    void traverse ( TreeNode *node, vector< vector<int> > &result, int depth ) {
        if ( node ) {
            if ( result.size() < depth+1 ) {
                vector<int> tmp;
                result.push_back( tmp );
            }
            result[depth].push_back( node->val );
            traverse( node->left, result, depth+1 );
            traverse( node->right, result, depth+1 );
        }
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > result;
        traverse ( root, result, 0 );
        return result;
    }
};
