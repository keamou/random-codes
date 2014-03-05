/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int mymin( int a, int b )
    {
        if ( a > b ) return b;
        return a;
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //DP problem
        int num_rows = (int) triangle.size();
        //if ( num_rows == 1 ) return triangle[0][0];
        //else if ( num_rows > 1 )
        //{
            vector<int> sums = triangle[num_rows-1];
            while ( num_rows > 1 )
            {
                -- num_rows;
                for ( int i=0; i<num_rows; i++ )
                {
                    sums[i] = mymin( triangle[num_rows-1][i] + sums[i], triangle[num_rows-1][i] + sums[i+1] );
                }
            }
        //}
        return sums[0];
    }
};
