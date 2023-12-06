#include<vector>
using namespace std;

class Solution {
private:
    int sum = 0;
    vector<int> res;
    vector<vector<int>> ans;
public:
    void backtracking(int startIndex, int k, int n){
        if (sum > n) return;
        if (res.size()==k){
            if (sum == n){
                ans.push_back(res);
                return;
            }
            return;
        }
        if (startIndex > 9) return;
        res.push_back(startIndex);
        sum += startIndex;
        backtracking(startIndex+1, k, n);
        res.pop_back();
        sum -= startIndex;
        backtracking(startIndex+1, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, k, n);
        return ans;
    }
};