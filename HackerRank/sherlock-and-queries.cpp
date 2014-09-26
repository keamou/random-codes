/*

Watson gives to Sherlock an array: A1,A2,⋯,AN. He also gives to Sherlock two other arrays: B1,B2,⋯,BM and C1,C2,⋯,CM. 
Then Watson asks Sherlock to perform the following program:

for i = 1 to M do
    for j = 1 to N do
        if j % B[i] == 0 then
            A[j] = A[j] * C[i]
        endif
    end do
end do
Can you help Sherlock and tell him the resulting array A? You should print all the array elements modulo (109+7).

Input Format 
The first line contains two integer numbers N and M. The next line contains N integers, the elements of array A. The next two lines contains M integers each, the elements of array B and C.

Output Format 
Print N integers, the elements of array A after performing the program modulo (109+7).

Constraints 
1≤N,M≤105 
1≤B[i]≤N 
1≤A[i],C[i]≤105
Sample Input

4 3
1 2 3 4
1 2 3
13 29 71
Sample Output

13 754 2769 1508    

*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n, m, k, t;
    long tmp = 1000000007, tmp2;
    cin >> n >> m;
    
    vector<long> A(n), B(m), C(m);
    for ( int i=0; i<n; i++ ) cin >> A[i];
    for ( int i=0; i<m; i++ ) cin >> B[i];
    for ( int i=0; i<m; i++ ) cin >> C[i];
    
    vector< vector<int> > X(m);
    for ( int i=0; i<m; i++ ) {
        X[ B[i]-1 ].push_back( i );
    }
    
    for ( int i=0; i<m; i++ ) {
        if ( X[i].empty() ) continue;
        tmp2 = 1;
        for ( int j=0; j<X[i].size(); j++ ) tmp2 = (tmp2 * C[ X[i][j] ]) % tmp;
        
        k = n/(i+1);
        for ( int j=1; j<=k; j++ ) {
            t = (i+1) * j - 1;
            A[t] = (A[t] * tmp2) % tmp;
        }
    }
    
    cout << A[0];
    for ( int i=1; i<n; i++ ) cout << " " << A[i];
    cout << endl;
    
    return 0;
}
