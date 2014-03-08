/*
Sort a linked list using insertion sort.
*/

/////////////////////////////////////////////////////////////////////////

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
    ListNode *insertionSortList(ListNode *head) {
        if ( head == NULL ) return head;
        ListNode *result = head;
        head = head->next;
        result->next = NULL;
        while( head != NULL ) {
            if ( head->val <= result->val ) {
                ListNode *tmp2 = head->next;
                head->next = result;
                result = head;
                head = tmp2;
                continue;
            }
            for ( ListNode *tmp = result; tmp != NULL; tmp = tmp->next ) {
                if ( tmp->next == NULL || tmp->next->val >= head->val ) {
                    ListNode *tmp2 = head->next;
                    head->next = tmp->next;
                    tmp->next = head;
                    head = tmp2;
                    break;
                }
            }
        }
        return result;
    }
};
