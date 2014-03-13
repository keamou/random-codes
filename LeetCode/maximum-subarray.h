/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

///////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if ( n == 0 ) return 0;
        int maxval = A[0], i=0;
        int posval = 0, ii = -1;
        if ( A[0] ) { posval = A[0]; ii = 0; }
        int larval = A[0];
        for ( int j=1; j<n; j++ ) larval = (A[j] > larval) ? A[j] : larval;
        for ( int j=1; j<n; j++ ) {
            int tmp = maxval + A[j];
            
            if ( A[j] > 0 ) {
                if ( ii == -1 ) ii = j; 
                posval += A[j];
            } else {
                posval = 0; ii = -1;
            }
            
            while ( i<=j && tmp-A[i] > tmp ) {
                tmp -= A[i];
                ++i;
            }
            
            if ( posval > 0 && posval > tmp ) {
                maxval = posval;
                i = ii;
            } else maxval = tmp;
            
            if ( maxval > 0 && maxval > larval ) {
                larval = maxval;
            }
        }
        return larval;
    }
};
