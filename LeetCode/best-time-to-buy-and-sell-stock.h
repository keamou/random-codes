/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

/////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if ( prices.empty() ) return 0;
        vector<int> maxvec( prices.size() );
        int maxval = prices.back(), result = 0;
        for ( int i=prices.size()-1; i>=0; i-- ) {
            maxval = (maxval < prices[i]) ? prices[i] : maxval;
            if ( maxval-prices[i] > result ) result = maxval-prices[i];
        }
        return result;
    }
};
