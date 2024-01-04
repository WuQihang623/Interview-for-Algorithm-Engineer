# include <vector>
# include <string>
# include <unordered_set>
# include<algorithm>
# include <unordered_map>
using namespace std;

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (nums.size()==path.size()) {
            ans.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            // 去重！！！
            if (i>0 && nums[i]==nums[i-1] && used[i]==false) continue;

            if (used[i]==false) {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false); // 用于记录下标
        backtrack(nums, used);
        return ans;
    }
};