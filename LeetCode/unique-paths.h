/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

////////////////////////////////////////////////////////////////////

class Solution {
public:
    int uniquePaths(int m, int n) {
        if ( m == 0 || n == 0 ) return 0;
        long long sum = m+n-2;
        if ( sum <= 0 ) return 1;
        long long minval = min( m-1, n-1 );
        if ( minval == 0 ) return 1;
        long long result = 1;
        for ( int i=1; i<=minval; i++, sum-- ) result = result * sum / i;
        return (int)result;
    }
};
