/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/////////////////////////////////////////////////////////////////

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct myCompare{
    bool operator() (Interval a, Interval b){ return (a.start < b.start); }
} mycompare;
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if ( intervals.empty() ) return intervals;
        sort( intervals.begin(), intervals.end(), mycompare );
        vector<Interval> result; result.push_back( intervals[0] );
        for ( int i=1; i<intervals.size(); i++ ) {
            if ( intervals[i].start <= result.back().end ) result.back().end = (result.back().end < intervals[i].end) ? intervals[i].end : result.back().end;
            else result.push_back( intervals[i] );
        }
        return result;
    }
};
