/*
Frequency Counting of Words / Top N words in a document.
Given N terms, your task is to find the k most frequent terms from given N terms.

Input format

First line of input contains N, denoting the number of terms to add.
In each of the next N lines, each contains a term.
Next line contains k, most frequent terms.

Output format

Print the k most frequent terms in descending order of their frequency. If two terms have same frequency print them in lexicographical order.

Sample input

14
Fee
Fi
Fo
Fum
Fee
Fo
Fee
Fee
Fo
Fi
Fi
Fo
Fum
Fee
3

Sample output

Fee
Fo
Fi

Constraint

0 < N < 300000
0 < term length < 25.
*/


/*
 * top_k2.cpp
 *
 *  Created on: Mar 1, 2014
 *      Author: edwlin
 */


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct mycompare {
	bool operator() ( const pair<int, string> & lhs, const pair<int, string> & rhs ) {
		if ( lhs.first < rhs.first ) {
			return true;
		} else if ( lhs.first > rhs.first) {
			return false;
		} else if ( lhs.first == rhs.first ) {
			if ( lhs.second > rhs.second ) return true;
			return false;
		}
	}
};

int main()
{
	int n, k = 0;
	char buffer[25];
	map<string, int> strmap;
	set< pair<int, string>, mycompare > strset;

	cin >> n;

	for ( int i=0; i<n; i++ ) {
		cin >> buffer;
		string str = string(buffer);
		map<string, int>::iterator itr = strmap.find( str );
		if ( itr == strmap.end() ) {
			strmap.insert( make_pair(str, 1) );
		} else {
			itr->second ++;
		}
	}

	cin >> k;
	
	for ( map<string, int>::iterator itr = strmap.begin(); itr != strmap.end(); itr++ ) {
		strset.insert( make_pair( itr->second, itr->first ) );
	}
	
	for ( set< pair<int, string>, mycompare >::reverse_iterator itr = strset.rbegin(); itr != strset.rend() && k > 0; itr++ ) {
		cout << itr->second << endl;
		-- k;
	}

	return 0;
}

