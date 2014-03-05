/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

///////////////////////////////////////////////////////////////////////////////////////

class myComp
{
public:
    bool operator() (const pair<int, int> & lhs, const pair<int, int>& rhs ) const
    {
        if ( lhs.first < rhs.first ) return false;
        return true;
    }
};


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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *head = NULL, *ptr = NULL;
        if ( lists.empty() ) return head;
        
        priority_queue< pair<int, int>, vector< pair<int, int>>, myComp > mypq;
        for ( int i=0; i<lists.size(); i++ ) {
            if ( lists[i] == NULL ) continue;
            mypq.push( make_pair( lists[i]->val, i ) );
        }
        
        while ( !mypq.empty() ) {
            pair<int, int> tmp = mypq.top();
            mypq.pop();
            if ( head == NULL ) {
                ptr = head = lists[ tmp.second ];
            } else {
                ptr->next = lists[ tmp.second ];
                ptr = ptr->next;
            }
            lists[ tmp.second ] = lists[ tmp.second ]->next;
            if ( lists[ tmp.second ] != NULL ) {
                mypq.push( make_pair( lists[tmp.second]->val, tmp.second ) );
            }
        }
        
        return head;
    }
};