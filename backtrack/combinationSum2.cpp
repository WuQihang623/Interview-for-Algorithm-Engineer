# include <vector>
# include <string>
# include<algorithm>
# include<iostream>
# include <unordered_map>
using namespace std;

class Solution {
private:
    int sum=0;
    vector<int> res;
    vector<vector<int>> ans;
public:
    void backtracking(int start_index, vector<int>& candidates, int target) {
        if (sum == target){
            ans.push_back(res);
            return;
        }
        if (start_index >= candidates.size() || sum > target) return;
        res.push_back(candidates[start_index]);
        sum += candidates[start_index];
        backtracking(start_index+1, candidates, target);
        res.pop_back();
        sum -= candidates[start_index];
        // 找到下面一个
        bool flag = false;
        for (int i=start_index; i<candidates.size(); i++) {
            if (candidates[start_index] != candidates[i]) {
                start_index = i - 1;
                flag = true;
                break;
            }
        }
        if (flag) backtracking(start_index + 1, candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        backtracking(0, candidates, target);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> candidates = {2};
    s.combinationSum2(candidates, 1);
    cout << 1 << endl;
    return 0;
}