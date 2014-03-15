/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

/////////////////////////////////////////////////////////////////////

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if ( n == 0 ) return n;
        int idx = 0;
        for ( int i=1; i<n; i++ ) {
            if ( A[idx] != A[i] ) A[++idx] = A[i];
            else if ( idx==0 || A[idx-1] != A[i] ) A[++idx] = A[i];
        }
        return (idx+1);
    }
};
