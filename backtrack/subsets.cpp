# include <vector>
# include <string>
# include<algorithm>
# include <unordered_map>
using namespace std;


class Solution {
private:
    vector<int> res = {};
    vector<vector<int>> ans;
public:
    void backward(int startIdx, const vector<int>& nums){
        if (startIdx >= nums.size()) return;
        for (int i = startIdx; i < nums.size(); i++){
            res.push_back(nums[i]);
            ans.push_back(res);
            backward(i+1, nums);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(res);
        backward(0, nums);
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> ans = s.subsets(nums);
}