/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector< pair<int, int> > array;
        for ( int i=0; i<numbers.size(); i++ ) array.push_back( make_pair(numbers[i], i+1) );
        sort( array.begin(), array.end() );
        int i=0, j=array.size()-1;
        vector<int> result(2);
        while ( i < j ) {
            int tmp = array[i].first + array[j].first;
            if ( tmp > target ) {
                -- j;
            } else if ( tmp < target ) {
                ++ i;
            } else {
                if ( array[i].second < array[j].second )
                {
                    result[0] = array[i].second;
                    result[1] = array[j].second;
                } else {
                    result[0] = array[j].second;
                    result[1] = array[i].second;
                }
                break;
            }
        }
        return result;
    }
};
