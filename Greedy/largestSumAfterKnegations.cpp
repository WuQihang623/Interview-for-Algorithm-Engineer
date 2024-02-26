# include<vector>
using namespace std;

// k次取反后最大化的数组和

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int i=0; i<k; i++) {
            int min = 101;
            int idx = 0;
            for (int j=0; j<nums.size(); j++) {
                if (min > nums[j]) {
                    min = nums[j];
                    idx = j;
                }
            }
            nums[idx] = -nums[idx];
        }
        int ans = 0;
        for (int x: nums) ans += x;
        return ans;
    }
};