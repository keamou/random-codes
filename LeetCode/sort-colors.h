/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

////////////////////////////////////////////////////

class Solution {
public:
    void sortColors(int A[], int n) {
        int rcounter = 0, wcounter = 0;
        int i=0, j=n-1;
        while ( i <= j && i < n ) {
            switch( A[i] ){
                case 0:
                {
                    A[rcounter] = 0;
                    rcounter ++;
                    ++i;
                }
                break;
                
                case 1:
                {
                    ++i;
                }
                break;
                
                case 2:
                {
                    while ( j>=0 && A[j] == 2 ) { --j; wcounter ++; }
                    if ( i < j ) {
                        swap( A[i], A[j] );
                        --j;
                        wcounter ++;
                    }
                }
                break;
            }
        }
        for ( int k=0; k<n-rcounter-wcounter; k++ ) {
            A[rcounter+k] = 1;
        }
    }
};
