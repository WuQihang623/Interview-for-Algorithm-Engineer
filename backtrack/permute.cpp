# include <vector>
# include <string>
# include <unordered_set>
# include<algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> path;
    unordered_set<int> uset;
    vector<vector<int>> ans;
public:
    void backtrack(const vector<int>& nums){
        if (path.size()==nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (uset.find(nums[i])==uset.end()){
                path.push_back(nums[i]);
                uset.insert(nums[i]);
                backtrack(nums);
                path.pop_back();
                uset.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtrack(const vector<int>& nums, vector<int>& used) {
        if (nums.size()==path.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (used[i]==0) {
                path.push_back(nums[i]);
                used[i] = 1;
                backtrack(nums, used);
                path.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used (nums.size(), 0);
        backtrack(nums, used);
        return ans;
    }
};