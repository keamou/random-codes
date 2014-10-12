/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/




class Solution {
public:
    int subMaxProduct(int A[], int s, int t) {
        int i=t, j=s-1, c=0, r=INT_MIN;
        for ( int k=s; k<t; k++ ) if ( A[k]<0 ) {
            if ( i>k ) i = k;
            if ( k>j ) j = k;
            ++ c;
        }
        if ( c%2 == 0 ) {
            for ( int k=s; k<t; k++ ) r = (r == INT_MIN) ? A[k] : r*A[k];
        } else {
            int r1=INT_MIN, r2=INT_MIN;
            for ( int k=s; k<j; k++ ) r1 = (r1 == INT_MIN) ? A[k] : r1*A[k];
            for ( int k=i+1; k<t; k++ ) r2 = (r2 == INT_MIN) ? A[k] : r2*A[k];
            r = max(r1, max(r2, max(A[i], A[j])));
        }
        return r;
    }

    int maxProduct(int A[], int n) {
        int r = INT_MIN;
        int i=0, j=0;
        while ( j<n ) {
            i = j;
            while ( i<n ) if ( A[i]==0 ) { ++i; } else { break; }
            j = i+1;
            while ( j<n ) if ( A[j] != 0 ) { ++j; } else { break; }
            if ( i>= n ) { r = max(r, 0); break; }
            r = max( r, subMaxProduct(A, i, j) );
            if ( i != 0 || j != n ) r = max( r, 0 );
            ++j;
        }
        return r;
    }
};
