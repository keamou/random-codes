/*

Given a word w, rearrange the letters of w to construct another word s in such a way that, s is lexicographically greater than w.

Input Format 
The first line of input contains t, number of test cases. Each of the next t lines contains w.

Constraints 
1≤t≤105 
1≤|w|≤100 
w will contain only lower case english letters and its' length will not exceed 100.

Output Format 
For each testcase, output a string lexicographically bigger than w in a separate line. In case of multiple possible answers, print the lexicographically smallest one and if no answer exists, print no answer.

Sample Input

3
ab
bb
hefg
Sample Output

ba
no answer
hegf
Explanation

Testcase 1 : There exists only one string greater than ab which can be built by rearranging ab. That is ba. 
Testcase 2 : Not possible to re arrange bb and get a lexicographically greater string. 
Testcase 3 : hegf is the next string ( lexicographically greater ) to hefg.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    string str;
    
    cin >> n;
    getline( cin, str );
    
    for ( int i=0; i<n; i++ ) {
        getline( cin, str );
        int mj = str.size()-1, md = -1;
        for ( int k=mj-1; k>=0; k-- ) {
            if ( str[k] < str[mj] ) { md = k; break; }
            if ( str[k] > str[mj] ) { mj = k; }
        }
        if ( md == -1 ) { cout << "no answer" << endl; continue; }
        for ( int k=str.size()-1; k>=mj; k-- ) {
            if ( str[k] > str[md] ) { swap( str[k], str[md] ); sort(str.begin()+md+1, str.end()); break; }
        }
        cout << str << endl;
    }
    
    return 0;
}
