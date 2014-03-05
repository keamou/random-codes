/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

//////////////////////////////////////////////////////////////////////////////////////

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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ( !head || !head->next ) return;
        ListNode* tmp = head;
        int sz = 0;
        while ( tmp ) {
            sz++;
            tmp = tmp->next;
        }
        if ( sz <= 2 ) return;
        int pivot = sz / 2;
        if ( sz % 2 ) pivot++;
        ListNode* newhead = NULL;
        int idx = 0;
        tmp = head;
        while ( tmp ) {
            ++idx;
            if ( idx > pivot && newhead == NULL ) {
                newhead = tmp;
                tmp = tmp->next;
                newhead->next = NULL;
            } else if ( idx > pivot && newhead ) {
                ListNode* ptr = tmp;
                tmp = tmp->next;
                ptr->next = newhead;
                newhead = ptr;
            } else {
                tmp = tmp->next;
            }
        }
        tmp = head;
        if ( sz % 2 ) --pivot;
        for ( int i=0; i<pivot; i++ ) {
            ListNode *ptr = newhead;
            newhead = newhead->next;
            ptr->next = tmp->next;
            tmp->next = ptr;
            tmp = ptr->next;
            if ( i == pivot - 1 ) {
                if ( sz % 2 ) {
                    tmp->next = NULL;
                } else {
                    ptr->next = NULL;
                }
            }
        }
    }
};
