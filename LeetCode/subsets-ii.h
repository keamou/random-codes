/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void subsetsWithoutDup(vector<int> &S, vector< vector<int> > &r, vector<int> &t, int pos) {
        r.push_back( t );
        for ( int i=pos; i<S.size(); i++ ) {
            if ( i>pos && S[i] == S[i-1] ) continue;
            t.push_back( S[i]);
            subsetsWithoutDup( S, r, t, i+1 );
            t.pop_back();
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> t;
        vector< vector<int> > r;
        if ( S.size() > 0 ) sort( S.begin(), S.end() );
        subsetsWithoutDup( S, r, t, 0 );
        return r;
    }
};
