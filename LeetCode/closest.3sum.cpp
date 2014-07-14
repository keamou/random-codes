/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


/*
// version 1
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int delta = INT_MAX;
        int sum = 0, sum2 = 0, sum3 = 0;
        for ( int i=0; i<num.size(); i++ ) {
            if ( (num[i]-target) >= delta ) break;
            for ( int j=i+1; j<num.size(); j++ ) {
                sum2 = num[i] + num[j];
                if ( (sum2-target) >= delta ) break;
                for ( int k=j+1; k<num.size(); k++ ) {
                    sum3 = sum2 + num[k];
                    if ( abs(sum3 - target) < delta ) {
                        sum = sum3;
                        delta = abs(sum3 - target);
                    }
                    if ( (sum3 - target) >= delta ) break;
                }
            }
        }
        return sum;
    }
};
*/

//version 2
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int delta = INT_MAX;
        int result, sum = 0, idx, jdx;
        for ( int i=0; i<num.size(); i++ ) {
            idx = i+1;
            jdx = num.size() -1;
            while ( idx < jdx ) {
                sum = num[i] + num[idx] + num[jdx];
                if ( sum == target) return sum;
                else if ( sum > target ) jdx--;
                else idx++;
                if ( abs(sum - target) < delta ) {
                    delta = abs(sum - target);
                    result = sum; 
                }
            }
        }
        return result;
    }
};
