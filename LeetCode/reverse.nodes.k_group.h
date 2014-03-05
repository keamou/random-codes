/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

///////////////////////////////////////////////////////////////////////////////////////

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ( head == NULL || k <= 1 ) return head;
        int sz = 0;
        ListNode *tmp = head;
        while ( tmp ) {
            ++ sz;
            tmp = tmp->next;
        }
        if ( k > sz ) return head;
        tmp = head;
        int r = 1;
        ListNode *mylast = NULL;
        while ( r*k <= sz ) {
            ListNode *first = tmp;
            ListNode *last = tmp;
            tmp = tmp->next;
            for ( int i=1; i<k; i++ ) {
                ListNode* mytmp = tmp;
                tmp = tmp->next;
                mytmp->next = last;
                last = mytmp;
            }
            first->next = tmp;
            if ( mylast ) mylast->next = last;
            mylast = first;
            if ( r == 1 ) head = last;
            ++r;
        }
        return head;
    }
};
