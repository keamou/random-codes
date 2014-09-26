/*

This problem is a programming version of Problem 42 from projecteuler.net

The nth term of a sequence of triangle numbers is given by, 
tn=12n(n+1)

so the first ten triangle numbers are: 
1,3,6,10,15,21,28,36,45,55,⋯
You are given an integer. If it is a triangular number tn, print the term n corresponding to this number, else print −1

Input Format 
First line of input contains an integer T denoting the number of testcases. Each of the next T lines contains an integer.

Output Format 
Print the answer corresponding to each test case in a new line.

Constraints 
1≤T≤105 
1≤tn≤1018
Sample Input #00:

3
2
3
55
Sample Output #00:

-1
2
10

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long n, t, m, k, p, q;
    cin >> n;
    
    while ( (--n) >= 0 ) {
        cin >> t;
        t *= 2;
        m = (long long) sqrt(t);
        p = k = m*m + m;
        q = m;
        while ( p < t ) {
            ++ q;
            p += 2 * q;
        }
        if ( p != t ) {
            p = k;
            q = m;
            while ( p > t ) {
                p -= 2 * q;
                -- q;
            }
        }
        if ( p == t ) cout << q << endl;
        else cout << "-1" << endl;
    }
    
    return 0;
}

