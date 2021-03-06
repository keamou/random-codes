/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

//////////////////////////////////////////////////////////////////////

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if ( n == 0 ) return 0;
        int spos = 0, epos = n-1, pos;
        while ( spos < epos ) {
            pos = (spos + epos)/2;
            if ( A[pos] > target ) epos = pos-1;
            else if ( A[pos] < target ) spos = pos+1;
            else return pos;
        }
        if ( A[spos] == target ) return spos;
        return ( (A[spos] > target) ? spos : spos+1 );
    }
};
