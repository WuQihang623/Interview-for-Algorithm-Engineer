# include <vector>
# include <string>
# include<algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    int sum=0;
    vector<int> res;
    vector<vector<int>> ans;
public:
    void backtracking(int start_index, vector<int>& candidates, int target){
        if (start_index >= candidates.size() || sum > target) return;
        if (sum == target){
            ans.push_back(res);
            return;
        }
        res.push_back(candidates[start_index]);
        sum += candidates[start_index];
        backtracking(start_index, candidates, target);
        res.pop_back();
        sum -= candidates[start_index];
        backtracking(start_index+1, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>()); // 降序排列
        backtracking(0, candidates, target);
        return ans;
    }
};