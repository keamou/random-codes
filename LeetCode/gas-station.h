/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if ( gas.size()<1 ) return -1;
        vector<int> delta(gas.size());
        vector<int> rminvec(delta.size());
        for ( int i=0; i<delta.size(); i++ ) delta[i] = gas[i] - cost[i];
        for ( int i=1; i<delta.size(); i++ ) delta[i] += delta[i-1];
        
        if ( delta.back()<0 ) return -1;
        
        rminvec.back() = delta.back();
        for ( int i=delta.size()-2; i>=0; i-- ) rminvec[i] = min( delta[i], rminvec[i+1] );
        
        if ( rminvec[0] >= 0 ) return 0;
        
        int val = delta[0], tmp;
        for ( int i=1; i<delta.size(); i++ ) {
            tmp = delta[i-1] - delta.back();
            if ( val >= tmp && rminvec[i] >= delta[i-1] ) return i;
            val = min( val, delta[i] );
        }
        return -1;
    }
};
