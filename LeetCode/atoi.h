/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

/////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int atoi(const char *str) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strlen( str );
        long long sum = 0;
        bool op1 = true;
        bool op2 = true;
        for ( int i=0; i<len; i++ )
        {
            if ( str[i] >= '0' && str[i] <= '9'  ) {
                op1 = false;
                if ( sum == 0 ) sum = str[i] - '0';
                else {
                    sum = sum * 10 + (str[i] - '0');
                }
            } else {
                if ( op1 && str[i] == '+' ) {
                    op1 = false;
                    op2 = true;
                }
                else if ( op1 && str[i] == '-' ) {
                    op1 = false;
                    op2 = false;
                }
                else if ( !op1 || str[i] != ' ' )
                {
                    break;
                }
            }
        }
        if ( !op2 ) sum = 0 - sum;
        if ( sum > 2147483647 ) sum = 2147483647;
        if ( sum < -2147483648 ) sum = -2147483648;
        return (int)sum;
    }
};
