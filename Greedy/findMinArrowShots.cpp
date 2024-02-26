# include<vector>
# include<algorithm>
using namespace std;

// 用最少数量的箭引爆气球


class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int nums = 1;
        int x_start = points[0][0];
        int x_end = points[0][1];
        for (int i=1; i<points.size(); i++) {
            x_start = max(x_start, points[i][0]);
            x_end = min(x_end, points[i][1]);
            if (x_start > x_end) {
                nums += 1;
                x_start = points[i][0];
                x_end = points[i][1];
            }
        }
        return nums;
    }
};