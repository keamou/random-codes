/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    void subFourSum( vector< vector<int> > &r, vector<int> &t, vector<int> &num, int sum, int idx, int target ) {
        if ( (int)t.size() >= 4 ) {
            if ( sum == target ) r.push_back( t );
        } else {
        	if (sum + (4-(int)t.size())*num.back() < target) return;
            for ( int i=idx; i<(int)num.size()-3+(int)t.size(); i++ ) {
                if ( i>idx && num[i] == num[i-1] ) continue;
                sum += num[i];
                if ( sum + num[i]*(3-(int)t.size()) > target ) break;
                t.push_back( num[i] );
                subFourSum( r, t, num, sum, i+1, target );
                t.pop_back();
                sum -= num[i];
            }
        }
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector<int> > r;
        vector<int> t;
        if ( num.size() == 0 ) return r;
        sort( num.begin(), num.end() );
        for ( int i=0; i<(int)num.size()-3; i++ ) {
            if ( i>0 && num[i] == num[i-1] ) continue;
            if ( num[i]*4 > target ) break;
            t.push_back( num[i] );
            subFourSum( r, t, num, num[i], i+1, target );
            t.pop_back();
        }
        return r;
    }
};
