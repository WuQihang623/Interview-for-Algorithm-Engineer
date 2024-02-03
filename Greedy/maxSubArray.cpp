# include<vector>
#include <cstdint>
using namespace std;

// 最大子数组和，贪心解法
// 这个解法只合适存在正数的情况

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count;
            if (count < 0) count = 0;
        }
        return result;
    }
};