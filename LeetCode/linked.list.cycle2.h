/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

////////////////////////////////////////////////////////////////////////

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
    ListNode *detectCycle(ListNode *head) {
        if ( head == NULL ) return false;
        ListNode *tmp = head, *tmp2 = head;
        while ( head != NULL && head->next != NULL ) {
            tmp = tmp->next; head = head->next->next;
            if ( tmp == head ) {
                while ( tmp != tmp2 ) {
                    tmp = tmp->next; tmp2 = tmp2->next;
                }
                return tmp;
            }
        }
        return NULL;
    }
};
