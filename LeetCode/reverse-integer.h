/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

//////////////////////////////////////////////////

class Solution {
public:
    int reverse(int x) {
        if ( x >= 0 ) {
            int tmp = 0;
            do {
                tmp = tmp * 10 + x % 10;
                x = x / 10;
            } while( x != 0 );
            x = tmp;
        } else {
            x = 0 - x;
            int tmp = 0;
            do {
                tmp = tmp * 10 + x % 10;
                x = x / 10;
            } while( x != 0 );
            x = 0 - tmp;
        }
        return x;
    }
};
