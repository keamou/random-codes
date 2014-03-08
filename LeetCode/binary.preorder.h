/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

///////////////////////////////////////////////////////////////////////////////

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if ( root == NULL ) return result;
        stack< TreeNode* > mystack;
        mystack.push( root );
        result.push_back( root->val );
        TreeNode *tmp = NULL;
        while( !mystack.empty() ) {
            if ( mystack.top()->left ) {
                if ( mystack.top()->right && mystack.top()->right == tmp ) {
                    tmp = mystack.top();
                    mystack.pop();
                    continue;
                }
                if ( mystack.top()->left != tmp ) {
                    result.push_back( mystack.top()->left->val );
                    mystack.push( mystack.top()->left );
                }
                else if ( mystack.top()->right ) {
                    if ( mystack.top()->right != tmp ) {
                        result.push_back( mystack.top()->right->val );
                        mystack.push( mystack.top()->right );
                    }
                    else {
                        tmp = mystack.top();
                        mystack.pop();
                    }
                } else {
                    tmp = mystack.top();
                    mystack.pop();
                }
            } else if ( mystack.top()->right ) {
                if ( mystack.top()->right != tmp ) {
                    result.push_back( mystack.top()->right->val );
                    mystack.push( mystack.top()->right );
                }
                else {
                    tmp = mystack.top();
                    mystack.pop();
                }
            } else {
                tmp = mystack.top();
                mystack.pop();
            }
        }
        return result;
    }
};
