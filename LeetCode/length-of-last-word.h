/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

//////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int i=len-1, size = 0, j;
        if ( i >=0 && s[i] == ' ' ) while( i>=0 ) { if (s[i] != ' ') break; --i; }
        j = i;
        while ( j>= 0 ) { if (s[j] == ' ') break; --j; }
        size = i-j;
        return size;
    }
};
