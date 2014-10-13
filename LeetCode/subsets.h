/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    void subsetsWithoutDup(vector<int> &S, vector< vector<int> > &r, vector<int> &t, int pos) {
        r.push_back( t );
        for ( int i=pos; i<S.size(); i++ ) {
            t.push_back( S[i]);
            subsetsWithoutDup( S, r, t, i+1 );
            t.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> t;
        vector< vector<int> > r;
        if ( S.size() > 0 ) sort( S.begin(), S.end() );
        subsetsWithoutDup( S, r, t, 0 );
        return r;
    }
};
