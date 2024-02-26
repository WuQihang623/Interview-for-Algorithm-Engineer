# include<vector>
using namespace std;

// 跳跃游戏
// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。


// 动态规划解法，超时了
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i=0; i<nums.size()-1; i++) {
            if (dp[i]==true) {
                for (int j=i; j<=(i+nums[i])&&j<nums.size(); j++) {
                    dp[j] = true;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

// 贪心解法
// 每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
// 局部最优推出全局最优，找不出反例，试试贪心！
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=0;
        for (int i=0; i<=step; i++) {
            step = max(i+nums[i], step);
            if (step>=nums.size()-1) return true;
        }
        return false;
    }
};
