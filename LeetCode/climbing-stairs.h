/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

///////////////////////////////////////////////

class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 1 ) return 1;
        if ( n == 2 ) return 2;
        int tmp1 = 1, tmp2 = 2, tmp;
        for ( int i=2; i<n; i++ ) {
            tmp = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        return tmp;
    }
};
