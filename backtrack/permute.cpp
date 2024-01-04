# include <vector>
# include <string>
# include <unordered_set>
# include<algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtrack(int startIdx, const vector<int>& nums){
        if (!path.empty()) {
            if (path.size()==nums.size()){
                ans.push_back(path);
                return;
            }
        }
        int uset[21] = {0};
        for (int i=0; i<nums.size(); i++) {
            bool flag = false;
            if (uset[nums[i]+10]!=0) {
                path.push_back(nums[i]);
                uset[nums[i]+10] += 1;
                flag = true;
            }
            backtrack(i+1, nums);
            if (flag) path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution s;
    s.permute(nums);
}