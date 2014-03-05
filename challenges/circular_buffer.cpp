/*
Implement a circular buffer of size N. Allow the caller to append, remove and list the contents of the buffer. Implement the buffer to achieve maximum performance for each of the operations.

The new items are appended to the end and the order is retained i.e elements are placed in increasing order of their insertion time. When the number of elements in the list elements exceeds the defined size, the older elements are overwritten.

There are four types of commands.

"A" n - Append the following n lines to the buffer. If the buffer is full they replace the older entries.
"R" n - Remove first n elements of the buffer. These n elements are the ones that were added earliest among the current elements.
"L" - List the elements of buffer in order of their inserting time.
"Q" - Quit.

Your task is to execute commands on circular buffer.

Input format

First line of input contains N , the size of the buffer.

A n - append the following n lines to the buffer.
R n - remove first n elements of the buffer.
L - list the buffer.
Q - Quit.

Output format

Whenever L command appears in the input, print the elements of buffer in order of their inserting time. Element that was added first should appear first.

Sample Input

10
A 3
Fee
Fi
Fo
A 1
Fum
R 2
L
Q

Sample Output

Fo
Fum

Constraint

0 <= N <= 10000
Number of removing elements will <= number of elements presents in circular buffer.
Total number of commands <= 50000.
Total number of characters in input <= 20000000.
*/

/*
 * circular_buffer2.cpp
 *
 *  Created on: Mar 1, 2014
 *      Author: edwlin
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if ( n == 0) return 0;
	
	char op;
	int num;
	char str[128];
	list<string> mylist;
	cin >> op;

	while ( op != 'Q' ) {
		switch ( op ) {
		case 'A':
		{
			cin >> num;
			
			if ( num > n ) {
				mylist.clear();
				while ( num > n ) {
					cin >> str;
					-- num;
				}
			} else {
				while ( mylist.size() + num > n ) {
					mylist.pop_front();
				}
			}
			
			for ( int i=0; i<num; i++ ) {
				cin >> str;
				string tmp = string( str );
				mylist.push_back( tmp );
			}
		}
		break;

		case 'R':
		{
			cin >> num;
			while ( num > 0 && !mylist.empty() ) {
				mylist.pop_front();
				-- num;
			}
		}
		break;

		case 'L':
		{
			for ( list<string>::iterator itr = mylist.begin(); itr != mylist.end(); itr++ ) {
				cout << *itr << endl;
			}
		}
		break;
		}

		cin >> op;
	}

	return 0;
}

