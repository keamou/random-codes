/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/


//////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result ( rowIndex + 1);
        result.front() = result.back() = 1;
        long long s1 = rowIndex, s2 = 1;
        for ( int i=1; i<=rowIndex/2; i++ ) {
            result[i] = (int) ((unsigned long long) result[i-1] * (unsigned long long)(rowIndex-i+1) / (unsigned long long)i);
        }
        if ( rowIndex % 2 == 0 ) {
            for ( int i=rowIndex/2+1; i<rowIndex; i++ ) {
                result[i] = result[ rowIndex/2 - (i-rowIndex/2) ];
            }
        } else {
            for ( int i=rowIndex/2+1; i<rowIndex; i++ ) {
                result[i] = result[ rowIndex/2 - (i-rowIndex/2) + 1 ];
            }
        }
        return result;
    }
};