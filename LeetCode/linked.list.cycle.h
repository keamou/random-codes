/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if ( head == NULL ) return false;
        ListNode *tmp = head; head = head->next;
        for ( ; head != NULL && head->next != NULL; tmp = tmp->next, head = head->next->next ) {
            if ( tmp == head ) {
                return true;
            }
        }
        return false;
    }
};
