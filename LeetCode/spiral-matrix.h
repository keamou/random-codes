/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

///////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if ( matrix.empty() ) return result;
        int i = 0, j = 0, size = 0;
        while ( j < matrix[0].size() - size && i < matrix.size()-size && j >=size && i >=size ) {
                for ( ;j < matrix[0].size() - size; j++ ) result.push_back( matrix[i][j] );
                --j;
                ++i;
                if ( i < matrix.size() - size ) {
                    for ( ;i < matrix.size() - size; i++ ) result.push_back( matrix[i][j] );
                    --i;
                    --j; 
                    if ( j >= size ) {
                        for ( ;j >= size; j-- ) result.push_back( matrix[i][j] );
                        ++j;
                        --i; 
                        if ( i > size ) {
                            for ( ;i > size; i-- ) result.push_back( matrix[i][j] );
                            ++i;
                        }
                    }
                }
                ++j;
                ++size;
        }
        return result;
    }
};
