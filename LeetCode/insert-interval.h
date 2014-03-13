/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if ( intervals.empty() ) {
            result.push_back( newInterval );
            return result;
        }
        int i = 0;
        for ( ; i<intervals.size(); i++ ) {
            if ( intervals[i].end >= newInterval.start ) break;
        }
        
        for ( int j=0; j<i; j++ ) result.push_back( intervals[j] );
        
        if ( i == intervals.size() ) {
            result.push_back ( newInterval );
        } else {
            if ( intervals[i].start > newInterval.end ) {
                result.push_back ( newInterval );
            } else {
                int start = min ( intervals[i].start, newInterval.start);
                for ( ++i ; i<intervals.size(); i++ ) {
                    if ( intervals[i].start > newInterval.end ) break;
                }
                int end = max( newInterval.end, intervals[i-1].end );
                Interval tmp ( start, end );
                result.push_back ( tmp );
            }
        }
        
        for ( int j=i; j<intervals.size(); j++ ) result.push_back( intervals[j] );
        
        return result;
    }
};
