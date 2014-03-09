/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

///////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if ( head == NULL ) return head;
        map< RandomListNode*, int > pointerMap;
        vector< RandomListNode* > pointerVector;
        for ( RandomListNode *tmp = head; tmp != NULL; tmp = tmp->next ) {
            pointerMap.insert( make_pair( tmp, pointerVector.size() ) );
            RandomListNode *elem = new RandomListNode( tmp->label );
            pointerVector.push_back( elem );
        }
        for ( int i=0; i<pointerVector.size()-1; i++ ) pointerVector[i]->next = pointerVector[i+1];
        int idx = 0;
        for ( RandomListNode *tmp = head; tmp != NULL; tmp = tmp->next, idx++) {
            if ( tmp->random == NULL ) continue;
            map< RandomListNode*, int >::iterator itr = pointerMap.find( tmp->random );
            if ( itr != pointerMap.end() ) {
                pointerVector[idx]->random = pointerVector[ itr->second ];
            }
        }
        return pointerVector[0];
    }
};
