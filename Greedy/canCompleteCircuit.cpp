# include<vector>
#include <climits>
using namespace std;

// 加油站

// 暴力解法， 超时

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> resGas (gas.size(), 0);
        for (int i=0; i<gas.size(); i++) {
            resGas[i] = gas[i] - cost[i];
        }
        for (int k=0; k<gas.size(); k++) {
            int res = 0;
            for (int i=0; i<gas.size(); i++) {
                res += resGas[(i+k)%gas.size()];
                if (res<0) break;
            }
            if (res>=0) return k;
        }
        return -1;
    }
};

// 贪心解法

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX; // 从起点出发，油箱里的油量最小值
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min) {
                min = curSum;
            }
        }
        if (curSum < 0) return -1;  // 情况1
        if (min >= 0) return 0;     // 情况2
                                    // 情况3
        for (int i = gas.size() - 1; i >= 0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }
        return -1;
    }
};
