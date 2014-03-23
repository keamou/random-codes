/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

////////////////////////////////////////

class Solution {
public:

    int search(int A[], int sidx, int eidx, int target) {
        if ( sidx > eidx ) return -1;
        int idx = (sidx + eidx)/2;
        if ( A[idx] == target ) return idx;
        if ( A[idx] > target ) {
            if ( A[sidx] < A[eidx] ) {
                return search( A, sidx, idx-1, target );
            } else {
                if ( A[idx] >= A[sidx] ) {
                    int tmp = search(A, sidx, idx-1, target);
                    if ( tmp != -1 ) return tmp;
                    return search( A, idx+1, eidx, target );
                } else {
                    return search( A, sidx, idx-1, target );
                }
            }
        } else {
            if ( A[sidx] < A[eidx] ) {
                return search( A, idx+1, eidx, target );
            } else {
                if ( A[idx] > A[sidx] ) {
                    return search( A, idx+1, eidx, target );
                } else {
                    int tmp = search(A, idx+1, eidx, target);
                    if ( tmp != -1 ) return tmp;
                    return search( A, sidx, idx-1, target );
                }
            }
        }
    }

    int search(int A[], int n, int target) {
        if ( n == 0 ) return -1;
        return search( A, 0, n-1, target );
    }
};
