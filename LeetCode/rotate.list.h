/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ( head == NULL || k == 0 ) return head;
        int sz = 0;
        ListNode * tmp = head;
        ListNode * tail = NULL;
        while ( tmp ) {
            ++ sz;
            tail = tmp;
            tmp = tmp->next;
        }
        if ( k % sz == 0 ) return head;
        int r = sz - k % sz;
        tmp = head;
        for ( int i=0; i<r-1; i++ ) tmp = tmp->next;
        tail->next = head;
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};
