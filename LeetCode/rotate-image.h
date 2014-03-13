/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

//////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for ( int i=0; i<matrix.size()/2; i++ ) {
            for ( int j=0; j<matrix.size()/2; j++ ) {
                int val = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i] = val;
            }
        }
        if ( matrix.size()%2 ) {
            for ( int i=0; i<matrix.size()/2; i++ ) {
                int j = matrix.size()/2;
                int val = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i] = val;
            }
        }
    }
};
