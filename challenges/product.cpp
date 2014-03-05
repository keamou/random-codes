/*
Given a list of integers, your task is to write a program to output an integer-valued list of equal length such that the output element at index 'i' is the product of all input elements except for the input element at 'i'.

In other words, let inputArray by an integer array of length 'n'. The solution,computed into outputArray, would be:

for each j from 1 to n-2:
outputArr[ j ] = inputArray[0] * inputArray[1] * inputArray[2] * ... * inputArray[j-1] * inputArray[j+1] * inputArray[j+2] *...* inputArray[n-1]

for j = 0
outputArray[0] = inputArray[1] * outputArray[2] * ... * outputArray[n-1]

for j = n-1
outputArray[n-1] = outputArray[0] * outputArray[1] * outputArray[2] * ... * outputArray[n-2]

As an example, if inputArray = { 1, 2, 3, 4 }, then
outputArray = { 2*3*4, 1*3*4, 1*2*4, 1*2*3 }.
Your program should run in O(n) time and should be space efficient.

Input format

First line of input contains N , number of elements in list.
Next N lines will each contain an element (a signed integer)

Output format

Print the output list of numbers.

Sample input

4
5
2
2
3

Sample output

12
30
30
20

Constraint

You may assume that:

The input array size will always have at least two elements in it, that is, n >= 2.
The product of any subset of the input will never exceed the value of a 64 bit integer.
The maximum length of input array is 1000.
*/

/*
 * product2.cpp
 *
 *  Created on: Mar 1, 2014
 *      Author: edwlin
 */


#include <iostream>
#include <vector>
using namespace std;

typedef long long ull;

int main()
{
	ull n, tmp, last, tmp2;
	cin >> n;

	vector<ull> array(n);
	vector<ull> elems(n, 1);

	for ( int i=0; i<n; i++ )
	{
		cin >> tmp;
		array[i] = tmp;
	}

	for ( int i=1; i<n; i++ )
	{
		elems[i] = elems[i-1] * array[i-1];
	}

	tmp = 1;
	for ( int i=n-2; i>=0; i-- )
	{
		tmp = tmp * array[i+1];
		elems[i] = elems[i] * tmp;
	}

	for (int i=0; i<n; i++ ) cout << elems[i] << endl;

	return 0;
}
