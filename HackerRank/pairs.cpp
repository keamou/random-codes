/*
Given N integers, count the number of pairs of integers whose difference is K.

Input Format 
The 1st line contains N & K (integers). 
The 2nd line contains N numbers of the set. All the N numbers are distinct.

Output Format 
An integer that tells the number of pairs of integers whose difference is K.

Constraints: 
N <= 105 
0 < K < 109 
Each integer will be greater than 0 and at least K smaller than 231-1

Sample Input #00:

5 2  
1 5 3 4 2  
Sample Output #00:

3
Sample Input #01:

10 1  
363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793 
Sample Output #01:

0
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector < int > a,int k) {
   int ans = 0, diff = 0;
    
    sort(a.begin(), a.end());
    for ( int i=1; i<a.size(); i++ ) {
        for ( int j=i-1; j>=0; j-- ) {
            diff = a[i] - a[j];
            if ( diff > k ) break;
            if ( diff == k ) ++ ans;
        }
    }
    
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}
