/*
Sometimes you need to compare lists of numbers, but sorting each one individually might take too much time. Instead you can use alternative methods to find the differences between each list.

Challenge 
Numeros, The Artist, was arranging two identical lists A and B in specific orders. The arrangements of the two arrays were random. Numeros was very proud of his arrangements. Unfortunately, while transporting his lists from one exhibition to another, some numbers got left out of List A. Can you find the missing numbers from A without messing up his order?

Details 
There are many duplicates possible in the lists, but you need to find the extra numbers, i.e., you have to find B - A. Print the numbers in numerical order. Print each missing number once, even if it is missing multiple times. The numbers are all within a range of 100 from each other.

Input Format 
There will be four lines of input:

n - the size of the first list 
This is followed by n numbers that make up the first list. 
m - the size of the second list 
This is followed by m numbers that make up the second list.

Output Format 
Output B-*A*, i.e., all the numbers (in ascending order) that are in B, but not in A.

Constraints 
1<= n,m <= 1000001 
-10000 <= x <= 10000 , x ∈ B 
Xmax - Xmin < 101

Sample Input

10
203 204 205 206 207 208 203 204 205 206
13
203 204 204 205 206 207 205 208 203 206 205 206 204
Sample Output

204 205 206
Explanation 
Although 204 is present in both the arrays, 204's frequency in A is smaller than that of B. Similarly, 205 and 206 occur twice in A, but thrice in B. So, these three numbers constitute the output. The rest of the numbers occur as many times in A as they do in B - so they are not "missing numbers".
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n, m;
    int *A, *B;
    int C[101] = {0};
    int minvalue = 10000;
    
    cin >> n;
    A = (int *) malloc(sizeof(int) * n);
    for (int i=0; i<n; i++) cin >> A[i];
    
    cin >> m;
    B = (int *) malloc(sizeof(int) * m);
    for (int i=0; i<m; i++) cin >> B[i];
    
    for (int i=0; i<m; i++) {
        if (B[i] < minvalue) minvalue = B[i];
    }
    
    for (int i=0; i<m; i++) {
        C[B[i] - minvalue] ++;
    }
    
    for (int i=0; i<n; i++) {
        C[A[i] - minvalue] --;
    }
    
    for (int i=0; i<101; i++) {
        if (C[i]) {
            cout << i+minvalue << " ";
        }
    }
    cout << endl;
    
    return 0;
}
