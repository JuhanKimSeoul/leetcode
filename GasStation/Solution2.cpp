#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        {
            return -1;
        }

        int x = 0;
        int accum_tank = 0;
        for(int i=0;i<gas.size();i++)
        {
            accum_tank = gas[i] - cost[i];
            
            if(accum_tank < 0)
            {
                accum_tank = 0;
                x = i+1;
            }
        }
        return x;
    }
};