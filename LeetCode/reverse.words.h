/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/


class Solution {
public:
    void reverseWords(string &s) {
        int spos = 0, epos = s.size()-1;
        while ( spos < s.size() && s[spos] == ' ' ) ++ spos;
        while ( epos < s.size() && s[epos] == ' ' ) -- epos;
        if ( spos > epos ) {
            s.clear();
            return;
        }
        s = s.substr( spos, epos-spos+1 );
        string tmp;
        for ( int i=0; i<s.size(); i++ ) {
            if ( s[i] != ' ' ) tmp.push_back( s[i] );
            else if ( s[i-1] != ' ' ) tmp.push_back( s[i] );
        }
        s = tmp;
        for ( int i=0; i<s.size()/2; i++ ) swap( s[i], s[s.size()-1-i] );
        spos = 0;
        for ( int i=0; i<s.size(); i++ ) {
            if ( s[i] == ' ' ) {
                for ( int j=spos; j<(i-spos)/2+spos; j++ ) swap( s[j], s[i-1-(j-spos)] );
                spos = i+1;
            }
        }
        if ( spos < s.size() ) {
            for ( int j=spos; j<(s.size()-spos)/2+spos; j++ ) swap( s[j], s[s.size()-1-(j-spos)] );
        }
    }
};
