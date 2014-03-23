/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

/////////////////////////////////////////

class Solution {
public:

    bool search(int A[], int sidx, int eidx, int target) {
        if ( sidx > eidx ) return false;
        int idx = (sidx + eidx)/2;
        if ( A[idx] == target ) return true;
        if ( A[idx] > target ) {
            if ( A[sidx] < A[eidx] ) {
                return search( A, sidx, idx-1, target );
            } else {
                if ( A[idx] >= A[sidx] ) {
                    if ( search(A, sidx, idx-1, target) ) return true;
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
                    if( search(A, idx+1, eidx, target) ) return true;;
                    return search( A, sidx, idx-1, target );
                }
            }
        }
    }

    bool search(int A[], int n, int target) {
        if ( n == 0 ) return false;
        return search( A, 0, n-1, target );
    }
};
