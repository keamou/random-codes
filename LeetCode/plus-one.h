/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

//////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if( digits.empty() ) {
            digits.push_back(1);
            return digits;
        }
        for ( int i=digits.size()-1; i>=0; i-- ) {
            if ( digits[i] + 1 > 9 ) digits[i] = 0;
            else {
                ++ digits[i];
                break;
            }
        }
        if ( digits[0] == 0 ) {
            vector<int> result( digits.size()+1, 0 ); result[0] = 1;
            return result;
        } else {
            return digits;
        }
    }
};
