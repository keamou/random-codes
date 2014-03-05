
/*
Sort a linked list in O(n log n) time using constant space complexity.
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

    ListNode *mergeSortedList(ListNode *list1, ListNode *list2) {
        if ( list1 == NULL ) return list2;
        if ( list2 == NULL ) return list1;
        ListNode *head = NULL, *tmp = NULL;
        if ( list1->val < list2->val ) {
            head = list1;
            list1 = list1->next;
            head->next = NULL;
        } else {
            head = list2;
            list2 = list2->next;
            head->next = NULL;
        }
        tmp = head;
        while ( list1 != NULL && list2 != NULL ) {
            if ( list1->val < list2->val ) {
                tmp->next = list1;
                list1 = list1->next;
                tmp = tmp->next;
                tmp->next = NULL;
            } else {
                tmp->next = list2;
                list2 = list2->next;
                tmp = tmp->next;
                tmp->next = NULL;
            }
        }
        if ( list1 != NULL ) tmp->next = list1;
        if ( list2 != NULL ) tmp->next = list2;
        return head;
    }

    ListNode *sortList(ListNode *head) {
        if ( head == NULL ) return head;
        int len = 0;
        for( ListNode *tmp = head; tmp != NULL; tmp = tmp->next ) len++;
        if ( len == 1 ) return head;
        if ( len == 2 ) {
            if ( head->val > head->next->val ) {
                int tmp = head->val;
                head->val = head->next->val;
                head->next->val = tmp;
            }
            return head;
        }
        ListNode *list1 = head, *list2 = head->next;
        for ( int i=1; i<len/2; i++ ) {
            list1 = list1->next;
            list2 = list1->next;
        }
        list1->next = NULL;
        list1 = head;
        list1 = sortList( list1 );
        list2 = sortList( list2 );
        head = mergeSortedList( list1, list2 );
        return head;
    }
};