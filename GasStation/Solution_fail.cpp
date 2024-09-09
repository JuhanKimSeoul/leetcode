#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            if(cost[i] > gas[i]) continue;

            int x = i;
            int accum_tank = gas[i];
            do
            {
                accum_tank -= cost[x];
                if(x+1 > gas.size()) x = 0;
                else x++;
                accum_tank += gas[x];
            } 
            while(x != i && accum_tank >= cost[x]);

            if(x == i) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> gas = {5,8,2,8};
    vector<int> cost = {6,5,6,6};
    int result = sol.canCompleteCircuit(gas, cost);
    printf("Result: %d\n", result);
    return 0;
}