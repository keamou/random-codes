/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int aidx = m-1, bidx = n-1, idx = m+n-1;
        while ( aidx >= 0 && bidx >= 0 ) {
            if ( A[aidx] > B[bidx] ) {
                A[idx] = A[aidx];
                -- idx; -- aidx;
            } else {
                A[idx] = B[bidx];
                -- idx; -- bidx;
            }
        }
        while ( aidx >= 0 ) {
            A[idx] = A[aidx];
            -- idx; -- aidx;
        }
        while ( bidx >= 0 ) {
            A[idx] = B[bidx];
            -- idx; -- bidx;
        }
    }
};
