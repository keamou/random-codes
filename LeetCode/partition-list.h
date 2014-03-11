/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if ( head == NULL ) return head;
        ListNode *tmp = head;
        int maxval = tmp->val;
        while ( tmp->next ) {
            if ( tmp->next->val < x && maxval >= x ) {
                maxval = max( maxval, tmp->next->val );
                if ( head->val >= x ) {
                    ListNode *tmp2 = tmp->next;
                    tmp->next = tmp->next->next;
                    tmp2->next = head;
                    head = tmp2;
                    continue;
                }
                ListNode *itr = head;
                while ( itr->next ) {
                    if ( itr->next->val >= x ) {
                        ListNode *tmp2 = tmp->next;
                        tmp->next = tmp->next->next;
                        tmp2->next = itr->next;
                        itr->next = tmp2;
                        break;
                    }
                    itr = itr->next;
                }
                continue;
            } 
            maxval = max( maxval, tmp->next->val );
            tmp = tmp->next;
        }
        return head;
    }
};
