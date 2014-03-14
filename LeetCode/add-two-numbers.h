/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

//////////////////////////////////////////////////////////////////////////

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        int mark = false;
        ListNode *head = new ListNode( (l1->val + l2->val) % 10 );
        if ( l1->val + l2->val > 9 ) mark = true;
        ListNode *tmp = head;
        l1 = l1->next;
        l2 = l2->next;
        while ( l1 && l2 ) {
            if ( mark ) {
                tmp->next = new ListNode( (l1->val + l2->val + 1) % 10 );
                if ( l1->val + l2->val + 1 > 9 ) mark = true;
                else mark = false;
                l1 = l1->next; l2 = l2->next; tmp = tmp->next;
            } else {
                tmp->next = new ListNode( (l1->val + l2->val) % 10 );
                if ( l1->val + l2->val > 9 ) mark = true;
                else mark = false;
                l1 = l1->next; l2 = l2->next; tmp = tmp->next;
            }
        }
        while ( l1 ) {
            if ( mark ) {
                tmp->next = new ListNode( (l1->val + 1) % 10 );
                if ( l1->val + 1 > 9 ) mark = true;
                else mark = false;
                l1 = l1->next; tmp = tmp->next;
            } else {
                tmp->next = new ListNode( l1->val );
                l1 = l1->next; tmp = tmp->next;
            }
        }
        while ( l2 ) {
            if ( mark ) {
                tmp->next = new ListNode( (l2->val + 1) % 10 );
                if ( l2->val + 1 > 9 ) mark = true;
                else mark = false;
                l2 = l2->next; tmp = tmp->next;
            } else {
                tmp->next = new ListNode( l2->val );
                l2 = l2->next; tmp = tmp->next;
            }
        }
        if ( mark ) {
            tmp->next = new ListNode( 1 );
        }
        return head;
    }
};
