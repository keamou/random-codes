/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

/////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string result;
        if ( strs.empty() ) return result;
        if ( strs.size() == 1 ) return strs[0];
        
        int minlen = strs[0].size();
        for ( int i=1; i<strs.size(); i++ ) {
            if ( strs[i].size() > minlen ) minlen = strs[i].size();
        }
        if ( minlen == 0 )  return result;
        int j=0;
        for ( ; j<minlen; j++ ) {
            char c = strs[0][j];
            bool op = true;
            for ( int i=1; i<strs.size(); i++ ) {
                if ( strs[i][j] != c ) {
                    op = false;
                    break;
                }
            }
            if ( !op ) { break; }
        }
        result = strs[0].substr(0, j);
        return result;
    }
};