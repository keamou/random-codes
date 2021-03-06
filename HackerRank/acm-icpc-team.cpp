/*
You are given a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not. Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.

Input Format

The first line contains two integers N and M separated by a single space, where N represents the number of people, and M represents the number of topics. N lines follow.
Each line contains a binary string of length M. In this string, 1 indicates that the ith person knows a particular topic, and 0 indicates that the ith person does not know the topic. Here, 1 ≤ i ≤ 2, and it denotes one of the persons in the team.

Output Format

On the first line, print the maximum number of topics a 2-people team can know. 
On the second line, print the number of 2-person teams that can know the maximum number of topics. 

Constraints

2 ≤ N ≤ 500 

1 ≤ M ≤ 500
Sample Input

4 5
10101
11100
11010
00101
Sample Output

5
2
Explanation 
(1, 3) and (3, 4) know all the 5 topics. So the maximal topics a 2-people team knows is 5, and only 2 teams can achieve this.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, m;
    string tmp;
    vector<string> v;
    
    cin >> n;
    cin >> m;
    getline(cin, tmp);
    
    for ( int i=0; i<n; i++ ) {
        getline(cin, tmp);
        v.push_back(tmp);
    }
    
    sort( v.begin(), v.end() );
    
    int md = -1, c = 0;
    for ( int i=n-1; i>=0; i-- ) {
        for ( int j=i-1; j>=0; j-- ) {
            int d = 0;
            for ( int k=m-1; k>=0; k-- ) {
                if ( v[i][k] == '1' || v[j][k] == '1' ) ++d;
                if ( (k+d) < md ) break;
            }
            if ( md == d ) { c++; }
            if ( md < d ) { md = d; c = 1; }
        }
    }
    
    cout << md << endl << c << endl;
    
    return 0;
}
