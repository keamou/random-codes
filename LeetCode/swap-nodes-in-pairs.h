/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

///////////////////////////////////////////////////////////////////

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
    ListNode *swapPairs(ListNode *head) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode *tmp = head->next, *tmp2;
        head->next = head->next->next;
        tmp->next = head;
        head = tmp;
        tmp = head->next;
        while ( tmp->next && tmp->next->next ) {
            tmp2 = tmp->next->next;
            tmp->next->next = tmp2->next;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
            tmp = tmp2->next;
        }
        return head;
    }
};
