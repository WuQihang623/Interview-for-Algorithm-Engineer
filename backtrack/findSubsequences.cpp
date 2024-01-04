# include <vector>
# include <string>
# include <unordered_set>
# include<algorithm>
# include <unordered_map>
using namespace std;


class Solution {
private:
    int last_num = INT64_MIN;
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtrack(int startIdx, const vector<int>& nums){
        if (path.size()>1) ans.push_back(path);

        unordered_set<int> uset; // 用于记录本层中出现过的元素
        for (int i=startIdx; i<nums.size(); i++){
            // 跳过
            if ((!path.empty()&&nums[i]<path.back()) || uset.find(nums[i])!=uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(i+1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};