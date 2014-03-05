/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int numsz = (int) num.size();
        vector< vector<int> > result;
        if ( numsz == 0 ) return (result);
        sort( num.begin(), num.end() );
        if ( num.back() < 0 ) return (result);
        for ( int i=0; i<numsz; i++ ) {
            if ( num[i] > 0 ) break;
            if ( i > 0 && num[i] == num[i-1] ) continue;
            if ( i>numsz-3 && num[i] + num[numsz-2] + num[numsz-1] < 0 ) break;
            for ( int j=i+1; j<numsz; j++ ) {
                if ( j>i+1 && num[j] == num[j-1] ) continue;
                if ( num[i] + num[j] > 0  ) break;
                if ( j>numsz-2 && num[i] + num[j] + num[numsz-1] < 0  ) break;
                for ( int t=j+1; t<numsz; t++ ) {
                    if ( num[j] < 0 && num[t] <= 0) continue;
                    if ( t>j+1 && num[t] == num[t-1] ) continue;
                    int sum3 = num[i] + num[j] + num[t];
                    if ( sum3 > 0 ) break;
                    if ( sum3 == 0 ) {
                        vector<int> tmp;
                        tmp.push_back ( num[i] ); tmp.push_back( num[j] ); tmp.push_back( num[t] );
                        result.push_back( tmp );
                    }
                }
            }
        }
        sort( result.begin(), result.end() );
        if ( !result.empty() ) {
            vector<int> lastvct = result[0];
            vector< vector<int> > tmp;
            tmp.push_back( lastvct );
            for ( int i=1; i<(int)result.size(); i++ ) {
                if ( result[i] != lastvct ) {
                    lastvct = result[i];
                    tmp.push_back( lastvct );
                }
            }
            result = tmp;
        }
        return result;
    }
};
