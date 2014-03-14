/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

//////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int trap(int A[], int n) {
        int skysum = 0, last = 0, i=0, k;
        while ( i<n ) {
            int j = i+1;
            for ( ; j<n; j++ ) {
                if ( A[j] > A[i] ) break;
            }
            if ( j == n ) break;
            skysum += A[i] * (j-i);
            i = j;
        }
        k = n-1;
        while ( k>=i ) {
            int j=k-1;
            for ( ; j>=i; j-- ) {
                if ( A[j] > A[k] ) break;
            }
            skysum += A[k] * (k-j);
            k = j;
        }
        for ( i=0; i<n; i++ ) skysum -= A[i];
        return skysum;
    }
};
