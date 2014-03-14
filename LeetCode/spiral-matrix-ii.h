/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

//////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix( n, vector<int>(n) );
        int i = 0, j = 0, size = 0, idx = 1;
        while ( j < n-size && i < n-size && j >=size && i >=size ) {
                for ( ;j < n - size; j++ ) matrix[i][j] = idx++;
                --j;
                ++i;
                if ( i < n - size ) {
                    for ( ;i < n - size; i++ ) matrix[i][j] = idx++;
                    --i;
                    --j; 
                    if ( j >= size ) {
                        for ( ;j >= size; j-- ) matrix[i][j] = idx++;
                        ++j;
                        --i; 
                        if ( i > size ) {
                            for ( ;i > size; i-- ) matrix[i][j] = idx++;
                            ++i;
                        }
                    }
                }
                ++j;
                ++size;
        }
        return matrix;
    }
};
