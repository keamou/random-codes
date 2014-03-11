/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int numTrees(int n) {
        if ( n <= 1 ) return n;
        vector<int> nums( n+1, 1 );
        for ( int i=2; i<=n; i++ ) {
            int tmp = 0;
            for ( int j=1; j<=i/2; j++ ) {
                tmp += nums[j-1] * nums[ i-j ];
            }
            tmp = tmp * 2;
            if ( i%2 ) tmp += nums[i/2] * nums[i/2];
            nums[i] = tmp;
        }
        return nums[n];
    }
};
