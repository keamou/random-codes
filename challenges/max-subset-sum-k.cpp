/*

Given a set S, find all the maximal subsets whose sum <= k. For example, if S = {1, 2, 3, 4, 5} and k = 7

Output is: {1, 2, 3} {1, 2, 4} {1, 5} {2, 5} {3, 4}

Hint:

- Output doesn’t contain any set which is a subset of other.

- If X = {1, 2, 3} is one of the solution then all the subsets of X {1} {2} {3} {1, 2} {1, 3} {2, 3} are omitted.

- Lexicographic ordering may be used to solve it

*/

/*
 * max-subset-sum-k.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: keamou
 */


/*
 * max-subset-sum-k.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: keamou
 */


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maxSubset( int curidx, vector<int> & tmp, int cursum, vector<int> & vals, int k )
{
	bool op = true;

	for ( int i=curidx+1; i<vals.size(); i++ ) {
		if ( cursum + vals[i] <= k ) {
			//if ( i>curidx && vals[i] == vals[i-1] ) continue;
			tmp.push_back( vals[i] );
			maxSubset ( i, tmp, cursum + vals[i], vals, k );
			tmp.pop_back();
			op = false;
		} else break;
	}

	if ( op ) {
		bool op2 = false;
		if ( tmp.size() > 0 ) {
			if ( (k-cursum)<vals[0] ) op2 = true;
			else {
				int j=0;
				for ( j=0; j<tmp.size(); j++ ) if ( tmp[j] != vals[j] ) break;
				if ( j == tmp.size() || (k-cursum) < vals[j] ) op2 = true;
			}
		}
		if ( op2 ) { for ( int i=0; i<tmp.size(); i++ ) cout << tmp[i] << " "; cout << endl; }
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vals(n);

	for ( int i=0; i<n; i++ ) cin >> vals[i];
	sort ( vals.begin(), vals.end() );

	for ( int i=0; i<n; i++ ) {
		if ( vals[i] <= k ) {
			//if ( i>0 && vals[i] == vals[i-1] ) continue;
			vector<int> tmp; tmp.push_back(vals[i]);
			maxSubset ( i, tmp, vals[i], vals, k );
			tmp.pop_back();
		}
	}

	return 0;
}


