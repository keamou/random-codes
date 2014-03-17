/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

//////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2);
        if ( n == 0 ) { result[0] = result[1] = -1; return result; }
        int spos = 0, epos = n-1, pos;
        while ( spos < epos ) {
            pos = (spos+epos)/2;
            if ( A[pos] >= target ) epos = pos-1;
            else if ( A[pos] < target ) spos = pos+1;
        }
        if ( epos < 0 || ( epos < n-1 && A[epos] < target) ) epos = epos+1;
        result[0] = epos;
        spos = 0, epos = n-1, pos;
        while ( spos < epos ) {
            pos = (spos+epos)/2;
            if ( A[pos] <= target ) spos = pos+1;
            else if ( A[pos] > target ) epos = pos-1;
        }
        if ( spos >= n || (spos > 0 && A[spos] > target) ) spos = spos-1;
        result[1] = spos;
        if ( result[0] == result[1] && A[result[0]] != target ) result[0] = result[1] = -1;
        if ( result[0] > result[1] ) result[0] = result[1] = -1;
        return result;
    }
};
