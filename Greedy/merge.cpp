# include<vector>
# include<algorithm>
using namespace std;

// 合并区间

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0]==b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int x_start = intervals[0][0];
        int x_end = intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            if (x_end < intervals[i][0]) {
                ans.push_back(vector<int> {x_start, x_end});
                x_start = intervals[i][0];
                x_end = intervals[i][1];
            }
            else {
                x_end = max(x_end, intervals[i][1]);
            }
        }
        ans.push_back(vector<int> {x_start, x_end});
        return ans;
    }
};


class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0]==b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else if (ans.back()[1] < intervals[i][1]) {
                ans.back()[1] = intervals[i][1];
            }
        }
        return ans;
    }
};