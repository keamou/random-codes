/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


//////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if ( num.empty() ) return 0;
        sort( num.begin(), num.end() );
        int len = 1, maxlen = 1;
        for ( int i=0; i<num.size()-1; i++ ) {
            if ( num[i]+1 == num[i+1] ) ++ len;
            else if ( num[i] == num[i+1] ) continue;
            else {
                maxlen = (len > maxlen ) ? len : maxlen;
                len = 1;
            }
        }
        maxlen = (len > maxlen ) ? len : maxlen;
        return maxlen;
    }
};
