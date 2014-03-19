/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

///////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if ( prices.empty() ) return 0;
        int maxval = prices.back(), result = 0;
        for ( int i=prices.size()-1; i>=0; i-- ) {
            if ( prices[i] < maxval ) result += maxval - prices[i];
            maxval = prices[i];
        }
        return result;
    }
};
