/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        for ( int k=0; k<s.size(); k++ ) if ( s[k] >= 'A' && s[k] <= 'Z' ) s[k] = s[k]-'A' + 'a';
        while ( i<j ) {
            if ( (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9') ) { ++i; continue; }
            if ( (s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9') ) { --j; continue; }
            if ( s[i] != s[j] ) return false;
            ++i; --j;
        }
        return true;
    }
};
