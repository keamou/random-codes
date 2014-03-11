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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> mystack;
        vector<int> result;
        if ( root == NULL ) return result;
        mystack.push( root );
        TreeNode *lastptr = NULL;
        while ( !mystack.empty() ) {
            if ( mystack.top()->left ) {
                if ( lastptr == mystack.top()->left ) {
                    result.push_back( mystack.top()->val );
                    if ( mystack.top()->right ) {
                        mystack.push( mystack.top()->right );
                    } else {
                        lastptr = mystack.top();
                        mystack.pop();
                    }
                } else {
                    if ( mystack.top()->right ) {
                        if ( lastptr == mystack.top()->right ) {
                            lastptr = mystack.top();
                            mystack.pop();
                            continue;
                        }
                    }
                    mystack.push( mystack.top()->left );
                }
            } else if ( mystack.top()->right ) {
                if ( lastptr == mystack.top()->right ) {
                    lastptr = mystack.top();
                    mystack.pop();
                } else {
                    result.push_back( mystack.top()->val );
                    mystack.push( mystack.top()->right );
                }
            } else {
                result.push_back( mystack.top()->val );
                lastptr = mystack.top();
                mystack.pop();
            }
        }
        return result;
    }
};
