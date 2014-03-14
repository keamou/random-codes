/*
Implement pow(x, n).
*/

//////////////////////////////////////////////////////////////

class Solution {
public:
    double pow(double x, int n) {
        if ( n == 0 ) return 1.0;
        else {
            double tmp = pow( x, n/2 );
            tmp = tmp * tmp;
            if ( n%2 ) {
                if ( n > 0 ) tmp = tmp * x;
                else tmp = tmp / x;
            }
            return tmp;
        }
    }
};
