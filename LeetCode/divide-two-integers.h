/*
Divide two integers without using multiplication, division and mod operator.
*/

//////////////////////////////

class Solution {
public:
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int result = 0;
        bool op = false;
        unsigned long long d1, d2;
        if ( (dividend < 0 && divisor > 0 ) || (dividend > 0 && divisor < 0) ) {
            op = true;
        }
        d1 = abs((long long)dividend);
        d2 = abs((long long)divisor);
        if ( d2 == 1 ) result = d1;
        else {
            while ( d1 >= d2 ) {
                int counter = 0;
                while ( (d2 << (counter+1)) <= d1 ) ++counter;
                result += (1 << counter);
                d1-= (d2 << counter);
            }
        }
        if ( op ) result = 0-result;
        return result;
    }
};
