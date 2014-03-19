/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if ( prices.empty() ) return 0;
        vector<int> maxvec( prices.size() );
        vector<int> minvec( prices.size() );
        int maxval = prices.back(), minval = prices.front(), result = 0, tmp;
        for ( int i=prices.size()-1; i>=0; i-- ) {
            maxval = (maxval < prices[i]) ? prices[i] : maxval;
            maxvec[i] = maxval - prices[i];
        }
        maxval = 0;
        for ( int i=prices.size()-1; i>=0; i-- ) {
            maxvec[i] = maxval = (maxval < maxvec[i]) ? maxvec[i] : maxval;
        }
        for ( int i=0; i<prices.size(); i++ ) {
            minvec[i] = minval = (minval > prices[i]) ? prices[i] : minval;
            minvec[i] = prices[i] - minval;
        }
        minval = 0;
        for ( int i=0; i<prices.size(); i++ ) {
            minvec[i] = minval = (minval < minvec[i]) ? minvec[i] : minval;
        }
        for ( int i=0; i<prices.size(); i++ ) {
            tmp = maxvec[i] + minvec[i];
            if ( tmp > result ) result = tmp;
        }
        return result;
    }
};
