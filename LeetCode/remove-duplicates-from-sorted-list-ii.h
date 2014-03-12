/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

///////////////////////////////////////////////////////////////////////

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
    ListNode *deleteDuplicates(ListNode *head) {
        while ( head && head->next && head->val == head->next->val ) {
            int val = head->val;
            do {
                head = head->next;
            } while ( head && head->val == val );
        }
        if ( head == NULL ) return head;
        ListNode *tmp = head;
        while ( tmp->next ) {
            bool op = true;
            while ( tmp->next && tmp->next->next && tmp->next->val == tmp->next->next->val ) {
                op = false;
                int val = tmp->next->val;
                ListNode *tmp2 = tmp->next->next;
                do {
                    tmp2 = tmp2->next;
                } while ( tmp2 && tmp2->val == val );
                tmp->next = tmp2;
            }
            if (op) tmp = tmp->next;
        }
        return head;
    }
};
