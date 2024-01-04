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
        for (int i = startIdx; i < nums.size(); ){
            res.push_back(nums[i]);
            ans.push_back(res);
            backward(i+1, nums);
            res.pop_back();
            bool flag = false;
            for (int j=i+1; j<nums.size(); j++){
                if (nums[j] != nums[j-1]){
                    i = j;
                    flag = true;
                    break;
                }
            }
            if (flag == false) return;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.push_back(res);
        sort(nums.begin(), nums.end());
        backward(0, nums);
        return ans;
    }
};