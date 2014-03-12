/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/////////////////////////////////////////////////////////////////////

class Solution {
public:
    string addBinary(string a, string b) {
        bool op = false;
        string str;
        while ( !a.empty() && !b.empty() ) {
            if ( a.back() == '1' ) {
                if ( b.back() == '1' ) {
                    if ( op ) str.push_back ( '1' );
                    else {
                        str.push_back ( '0' );
                        op = true;
                    }
                } else {
                    if ( op ) str.push_back ( '0' );
                    else str.push_back ( '1' );
                }
            } else {
                if ( b.back() == '1' ) {
                    if ( op ) str.push_back ( '0' );
                    else str.push_back ( '1' );
                } else {
                    if ( op ) {
                        str.push_back( '1' );
                        op = false;
                    } else str.push_back( '0' );
                }
            }
            a.pop_back();
            b.pop_back();
        }
        while ( !a.empty() ) {
            if ( a.back() == '1' ) {
                if (op) str.push_back( '0' );
                else str.push_back( '1' );
            } else {
                if ( op ) {
                    str.push_back( '1' );
                    op = false;
                } else str.push_back( '0' );
            }
            a.pop_back();
        }
        while ( !b.empty() ) {
            if ( b.back() == '1' ) {
                if (op) str.push_back( '0' );
                else str.push_back( '1' );
            } else {
                if ( op ) {
                    str.push_back( '1' );
                    op = false;
                } else str.push_back( '0' );
            }
            b.pop_back();
        }
        if ( op ) str.push_back( '1' );
        reverse( str.begin(), str.end() );
        return str;
    }
};
