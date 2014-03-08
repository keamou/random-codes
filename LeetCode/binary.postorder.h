/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/////////////////////////////////////////////////////////////////////////////////////////

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if ( root == NULL ) return result;
        stack< TreeNode* > mystack;
        mystack.push( root );
        TreeNode *tmp = NULL;
        while( !mystack.empty() ) {
            if ( mystack.top()->left ) {
                if ( mystack.top()->right && mystack.top()->right == tmp ) {
                    result.push_back( mystack.top()->val );
                    tmp = mystack.top();
                    mystack.pop();
                    continue;
                }
                if ( mystack.top()->left != tmp ) mystack.push( mystack.top()->left );
                else if ( mystack.top()->right ) {
                    if ( mystack.top()->right != tmp ) mystack.push( mystack.top()->right );
                    else {
                        result.push_back( mystack.top()->val );
                        tmp = mystack.top();
                        mystack.pop();
                    }
                } else {
                    result.push_back( mystack.top()->val );
                    tmp = mystack.top();
                    mystack.pop();
                }
            } else if ( mystack.top()->right ) {
                if ( mystack.top()->right != tmp ) mystack.push( mystack.top()->right );
                else {
                    result.push_back( mystack.top()->val );
                    tmp = mystack.top();
                    mystack.pop();
                }
            } else {
                result.push_back( mystack.top()->val );
                tmp = mystack.top();
                mystack.pop();
            }
        }
        return result;
    }
};
