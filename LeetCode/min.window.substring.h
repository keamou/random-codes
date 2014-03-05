/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string minWindow(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string result;
        if ( S.empty() || T.empty() ) return result;
        char maxchar = 0;
        for ( int i=0; i<T.size(); i++ ) if ( T[i] > maxchar ) maxchar = T[i];
        maxchar++;
        int mycounter = 0;
        vector<int> counter1 ( maxchar, 0 );
        vector<int> counter2 ( maxchar, 0 );
        vector<int> histogram ( maxchar, 0 );
        for ( int i=0; i<T.size(); i++ ) histogram[ T[i] ] ++;
        queue<int> myqueue;
        int delta = -1, idx1 = 0;
        for ( int i=0; i<S.size(); i++ ) {
            if ( S[i] < maxchar && histogram[ S[i] ] != 0 ) {
                myqueue.push( i );
                if ( counter1[ S[i] ] < histogram[ S[i] ] ) {
                    counter1[ S[i] ] ++;
                    counter2[ S[i] ] ++;
                    mycounter ++;
                } else {
                    counter2[ S[i] ] ++;
                }
                if ( mycounter == T.size() ) {
                    int tmp_delta = myqueue.back() - myqueue.front() + 1;
                    if ( delta == -1 || delta > tmp_delta ) {
                        idx1 = myqueue.front();
                        delta = tmp_delta;
                    }
                    while ( !myqueue.empty() && mycounter == T.size() ) {
                        int idx = myqueue.front();
                        char c = S[ idx ];
                        counter2[ c ] --;
                        myqueue.pop();
                        if ( counter2[ c ] < histogram[ c ] ) {
                            counter1[ c ] --;
                            mycounter --;
                            if ( !myqueue.empty() ) {
                                tmp_delta = myqueue.back() - idx + 1;
                                if ( delta > tmp_delta ) {
                                    idx1 = idx;
                                    delta = tmp_delta;
                                }
                            }
                        }
                    }
                }
            }
        }
        if ( delta == -1 ) return result;
        result = S.substr( idx1, delta );
        return result;
    }
};
