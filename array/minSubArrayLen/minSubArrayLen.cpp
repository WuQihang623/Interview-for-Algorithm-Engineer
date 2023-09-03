# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
    // 暴力求解
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int minLen = nums.size() + 1;
    //     int size = nums.size();
    //     for (int i = 0; i < size; i++){
    //         int val = 0;
    //         for (int j = i; j < size; j++){
    //             val += nums[j];
    //             if (val >= target){
    //                 if (minLen > (j-i+1)) minLen = (j-i+1);
    //                 break;
    //             }
    //         }
    //     }
    //     if (minLen == size+1) return 0;
    //     return minLen;
    // }

    // 滑动窗口
    int minSubArrayLen(int target, vector<int>& nums){
        int i = 0; // 记录起始位置
        int minLen = INT32_MAX;
        int val = 0;
        for (int j=0; j<nums.size(); j++){ // j是终点位置
            val += nums[j];
            // 移动起点位置
            while(val >= target){
                minLen = (j-i+1) < minLen ? (j-i+1) : minLen;
                val -= nums[i++];
            }
        }
        minLen = minLen == INT32_MAX ? 0: minLen;
        return minLen;
    }
};


int main(){
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    int target = 10;
    int minLen = solution.minSubArrayLen(target, nums);
    cout << minLen << endl;
    return 0;
}
