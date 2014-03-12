/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

////////////////////////////////////////////////////////////////

class Solution {
public:
    bool check( vector< vector<char> > & board, vector< vector<bool> > & marks, string & word, int idx, pair<int, int> pos ) {
        if ( idx >= word.size() ) return true;
        if ( pos.first < board.size()-1 ) {
            if ( !marks[pos.first+1][pos.second] && board[pos.first+1][pos.second] == word[idx] ) {
                marks [ pos.first+1][pos.second ] = true;
                if ( check( board, marks, word, idx+1, make_pair(pos.first+1, pos.second) ) ) return true;
                marks [ pos.first+1][pos.second ] = false;
            }
        }
        if ( pos.first > 0 ) {
            if ( !marks[pos.first-1][pos.second] && board[pos.first-1][pos.second] == word[idx] ) {
                marks [ pos.first-1][pos.second ] = true;
                if ( check( board, marks, word, idx+1, make_pair(pos.first-1, pos.second) ) ) return true;
                marks [ pos.first-1][pos.second ] = false;
            }
        }
        if ( pos.second < board[0].size()-1 ) {
            if ( !marks[pos.first][pos.second+1] && board[pos.first][pos.second+1] == word[idx] ) {
                marks [ pos.first][pos.second+1] = true;
                if ( check( board, marks, word, idx+1, make_pair(pos.first, pos.second+1) ) ) return true;
                marks [ pos.first][pos.second+1] = false;
            }
        }
        if ( pos.second > 0 ) {
            if ( !marks[pos.first][pos.second-1] && board[pos.first][pos.second-1] == word[idx] ) {
                marks [ pos.first][pos.second-1] = true;
                if ( check( board, marks, word, idx+1, make_pair(pos.first, pos.second-1) ) ) return true;
                marks [ pos.first][pos.second-1] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if ( word.size() == 0 ) return true;
        vector< vector<bool> > marks ( board.size(), vector<bool>(board[0].size(), false) );
        for ( int i=0; i<board.size(); i++ ) for ( int j=0; j<board[i].size(); j++ ) {
            if ( board[i][j] == word[0] ) {
                marks[i][j] = true;
                if ( check( board, marks, word, 1, make_pair(i, j) ) ) return true;
                marks[i][j] = false;
            }
        }
        return false;
    }
};
