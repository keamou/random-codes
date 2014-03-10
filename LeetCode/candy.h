/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


//////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int candy(vector<int> &ratings) {
        if ( ratings.size() == 0 ) return 0;
        if ( ratings.size() == 1 ) return 1;
        vector<int> nums( ratings.size(), 0 );
        multimap< int, int > rmap;
        for ( int i=0; i<ratings.size(); i++ ) rmap.insert( make_pair(ratings[i], i) );
        for ( multimap< int, int >::iterator itr = rmap.begin(); itr != rmap.end(); itr++ ) {
            int min_num = 1;
            if ( itr->second == 0 ) {
                if ( ratings[0] > ratings[1] ) min_num = max( min_num, nums[1]+1 );
                //else min_num = max( min_num, nums[1] );
            } else if ( itr->second == ratings.size()-1 ) {
                if ( ratings[itr->second] > ratings[itr->second-1] ) min_num = max( min_num, nums[itr->second-1]+1 );
                //else min_num = max( min_num, nums[itr->second-1] );
            } else {
                if ( ratings[itr->second] > ratings[itr->second-1] ) min_num = max( min_num, nums[itr->second-1]+1 );
                //else min_num = max( min_num, nums[itr->second-1] );
                if ( ratings[itr->second] > ratings[itr->second+1] ) min_num = max( min_num, nums[itr->second+1]+1 );
                //else min_num = max( min_num, nums[itr->second+1] );
            }
            nums[ itr->second ] = min_num;
        }
        int result = 0;
        for ( int i=0; i<nums.size(); i++ ) result += nums[i];
        return result;
    }
};
