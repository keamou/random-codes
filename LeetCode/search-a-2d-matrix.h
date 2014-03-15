/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

/////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if ( matrix.empty() ) return false;
        if ( matrix[0].front() > target || matrix[ matrix.size()-1 ].back() < target ) return false;
        int spos = 0, epos = matrix.size()-1, pos;
        while ( spos < epos ) {
            pos = (spos + epos)/2;
            if ( matrix[pos][0] > target ) epos = pos-1;
            else if ( matrix[pos][0] < target ) {
                if ( matrix[pos].back() < target ) spos = pos+1;
                else if ( matrix[pos].back() > target ) { spos = pos; break; }
                else return true;
            }
            else return true;
        }
        int idx = spos;
        spos = 0, epos = matrix[0].size()-1;
        while ( spos < epos ) {
            pos = (spos + epos)/2;
            if ( matrix[idx][pos] > target ) epos = pos-1;
            else if ( matrix[idx][pos] < target ) spos = pos+1;
            else return true;
        }
        if ( matrix[idx][spos] == target ) return true;
        return false;
    }
};
