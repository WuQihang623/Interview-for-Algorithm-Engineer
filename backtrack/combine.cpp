# include <vector>

using namespace std;

class Solution {
private:
    vector<int> vec;
    vector<vector<int>> ans;
public:
    void backtracking(int start, int end, int k){
        if ((end - start + 1 + vec.size()) < k) return;
        if (vec.size()==k){
            ans.push_back(vec);
            return ;
        }

        vec.push_back(start);
        backtracking(start+1, end, k);
        vec.pop_back();
        backtracking(start+1, end, k);
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return ans;
    }
};

int main(){
    Solution s;
    s.backtracking(1, 4, 2);
    return 0;
}