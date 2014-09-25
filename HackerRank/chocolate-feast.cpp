/*
Little Bob loves chocolates, and goes to a store with $N in his pocket. The price of each chocolate is $C. The store offers a discount: for every M wrappers he gives to the store, he gets one chocolate for free. How many chocolates does Bob get to eat?

Input Format: 
The first line contains the number of test cases T(<=1000). 
T lines follow, each of which contains three integers N, C and M

Output Format: 
Print the total number of chocolates Bob eats.

Constraints: 
2≤N≤105 
1≤C≤N 
2≤M≤N

Sample input

3
10 2 5
12 4 4
6 2 2
Sample Output

6
3
5
Explanation 
In the first case, he can buy 5 chocolates with $10 and exchange the 5 wrappers to get one more chocolate. Thus, the total number of chocolates is 6.

In the second case, he can buy 3 chocolates for $12. However, it takes 4 wrappers to get one more chocolate. He can't avail the offer and hence the total number of chocolates remains 3.

In the third case, he can buy 3 chocolates for $6. Now he can give 2 of this 3 wrappers and get 1 chocolate. Again, he can use his 1 unused wrapper and 1 wrapper of new chocolate to get one more chocolate. So the total is 5.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m, tmp;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        // Computer answer
        answer = n/c;
        tmp = answer;
        do {
            answer += tmp/m;
            tmp = tmp/m + tmp%m;
        } while ( tmp >= m );
        
        cout<<answer<<endl;
    }
    return 0;
}
