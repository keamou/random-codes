/*
Princess Peach is trapped in one of the four corners of a square grid. You are in the center of the grid and can move one step at a time in any of the four directions. Can you rescue the princess?

Input format

The first line contains an odd integer N (3 <= N < 100) denoting the size of the grid. This is followed by an NxN grid. Each cell is denoted by ‘-‘ (ascii value: 45). The bot position is denoted by ‘m’ and the princess position is denoted by ‘p’.

Grid is indexed using Matrix Convention

Output format

Print out all the moves you take to rescue the princess in one go. The moves must be separated by ‘\n’, a newline. The valid outputs are LEFT or RIGHT or UP or DOWN.

Sample input

3
---
-m-
p--
Sample output

DOWN
LEFT
Task

Complete the function displayPathtoPrincess which takes in two parameters - the integer N and the character array grid. The grid will be formatted exactly as you see it in the input, so for the sample input the princess is at grid[2][0]. The function shall output moves (LEFT, RIGHT, UP or DOWN) on consecutive lines to rescue/reach the princess. The goal is to reach the princess in as few moves as possible.

The above sample input is just to help you understand the format. The princess (‘p’) can be in any one of the four corners

Scoring
Your score is calculated as follows : (NxN - number of moves made to rescue the princess)/10, where N is the size of the grid (3x3 in the sample testcase).
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
     pair<int, int> mpos(-1, -1), ppos(-1, -1), moves;
  for ( int i=0; i<n; i++ ) for (int j=0; j<n; j++ ) {
    if ( grid[i][j] == 'm' ) mpos = make_pair( i, j );
    if ( grid[i][j] == 'p' ) ppos = make_pair( i, j );
    if ( mpos.first != -1 && ppos.first != -1 ) break;
  }
  moves = make_pair( mpos.first-ppos.first, mpos.second-ppos.second );
  if ( moves.first >= 0 ) {
    for ( int i=0; i<moves.first; i++ ) cout << "UP" << endl;
  } else {
    for ( int i=0; i>moves.first; i-- ) cout << "DOWN" << endl;
  }
  if ( moves.second >= 0 ) {
    for ( int i=0; i<moves.second; i++ ) cout << "LEFT" << endl;
  } else {
    for ( int i=0; i>moves.second; i-- ) cout << "RIGHT" << endl;
  }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}

