/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strlen( s );
        int pos = 0;
        while ( pos < len && s[pos] == ' ' ) ++pos;
        bool op1 = true, op2 = true, op = false;
        long long sum1 = 0, sum2 = 0;
        if ( pos < len && ( s[pos] < '0' || s[pos] > '9' ) && s[pos] != '.' )
        {
            if ( s[pos] == '+' || s[pos] == '-' ) ++ pos;
            else return false;
        }
        
        while ( pos < len ) {
            if ( s[pos] == ' ' || s[pos] == '\0' ) { ++pos; break; }
            if ( s[pos] >= '0' && s[pos] <= '9' ) {
                ++ pos;
                op = true;
                if ( !op1 ) {
                    if ( sum2 == 0 ) sum2 = s[pos] - '0';
                    else sum2 = sum2 * 10 + s[pos] - '0';
                } else {
                    if ( sum1 == 0 ) sum1 = s[pos] - '0';
                    else sum1 = sum1 * 10 + s[pos] - '0';
                }
                continue;
            }
            if ( s[pos] != '.' && s[pos] != 'e' ) return false;
            if ( s[pos] == '.' ) {
                if ( !op2 ) return false;
                if ( op1 ) {
                    op1 = false;
                }else {
                    return false;
                }
            }
            else if ( s[pos] == 'e' ) {
                if ( pos == len - 1 ) return false;
                else if ( s[pos+1] < '0' || s[pos+1] > '9' ) {
                    if ( s[pos+1] == '+' || s[pos+1] == '-' ) {
                        ++ pos;
                        if ( pos == len - 1 ) return false;
                        if ( s[pos+1] < '0' || s[pos+1] > '9' ) {
                            return false;
                        } else ++ pos;
                    } else return false;
                } else ++ pos;
                if ( sum1 == 0 && sum2 == 0 ) return false;
                if ( !op ) return false;
                sum1 = sum2 = 0;
                if ( op2 ) {
                    op2 = false;
                } else {
                    return false;
                }
            }
            ++pos;
        }
        while ( pos < len && (s[pos] == ' ' || s[pos] == '\0') ) ++ pos;
        if( pos < len || op == false ) return false;
        return true;
    }
};
