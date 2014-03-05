/*
Given a string s, we say s is unique iff all characters in s are different.

Given two strings s1 and s2, we say s1 is more beautiful than s2 iff (i) s1 is longer than s2, or (ii) the size of s1 equals the size of s2, and s1 is larger than s2 in alphabetical order.

Question: given a string s, find the most beautiful unique substring of s.
*/

/*
 * beautiful_string.cpp
 *
 *  Created on: Mar 2, 2014
 *      Author: edwlin
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    string str;
    getline( cin, str );
    
    vector<bool> marks( 26, false );
    vector<int> stats( 26, 0 );
    string best, cur;
    
    for ( int i=0; i<str.size(); i++ ) stats[ str[i] - 'a' ]++;
    
    vector<int> cur_stats( 26, 0 );
    
    
    for ( int i=0; i<str.size(); ) {
        int idx = str[i] - 'a';
        if ( marks[idx] ) {
            ++i;
            continue;
        }
        if ( cur_stats[ idx ] + 1 < stats[ idx ] ) {
            
            int large_char = str[i];
            int large_pos = i;
            vector<int> tmp_stats = cur_stats;
            tmp_stats[ idx ] ++;
            for ( int j=i+1; j<str.size(); j++ ) {
                int tmp_idx = str[j]-'a';
                if ( marks[tmp_idx] ) continue;
                if ( str[j] > large_char ) {
                    large_char = str[j];
                    large_pos = j;
                }
                tmp_stats[ tmp_idx ] ++;
                if ( tmp_stats[ tmp_idx ] >= stats[ tmp_idx] ) {
                    break;
                }
            }
            
            if ( large_char >= str[i] ) {
                best.push_back( large_char );
                marks[ large_char-'a' ] = true;
                for ( int j=i; j<=large_pos; j++ ) {
                    int tmp_idx = str[j] - 'a';
                    cur_stats[ tmp_idx ] ++;
                }
                i = large_pos+1;
            }
            
        } else if ( cur_stats[ idx ] + 1 == stats[ idx ] ){
            best.push_back( str[i] );
            marks[idx] = true;
            cur_stats[ idx ] ++;
            ++i;
        } else {
            ++i;
        }
    }
    
    cout << best << endl;
    
    return 0;
}
