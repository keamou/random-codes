/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/////////////////////////////////////////////////////////////////////////////

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    TreeLinkNode * findNext( TreeLinkNode *node ){
        if ( node->next == NULL ) return NULL;
        while ( node->next ) {
            if ( node->next->left ) return node->next->left;
            if ( node->next->right ) return node->next->right;
            node = node->next;
        }
        return NULL;
    }
    
    bool dfs( TreeLinkNode *root ) {
        if ( root == NULL ) return false;
        bool op = false;
        if ( root->left ) {
            if ( root->right ) root->left->next = root->right;
            else {
                TreeLinkNode *tmp = findNext( root );
                if ( tmp != root->left->next) {
                    root->left->next = tmp;
                    op = true;
                }
            }
        }
        if ( root->right ) {
            TreeLinkNode *tmp = findNext( root );
            if ( tmp != root->right->next ) {
                root->right->next = tmp;
                op = true;
            }
        }
        op |= dfs( root->left );
        op |= dfs( root->right );
        return op;
    }
    
    void connect(TreeLinkNode *root) {
        while( dfs( root ) );
    }
};
