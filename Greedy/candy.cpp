# include<vector>
# include<algorithm>
using namespace std;

// 分发糖果

// 先确定右边评分大于左边的情况
// 再确定左孩子大于右孩子的情况

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 1);
        for (int i=1; i<ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) candys[i] = candys[i-1] + 1;
        }
        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candys[i] = max(candys[i+1]+1, candys[i]);
            }
        }
        int ans = 0;
        for (int x: candys) ans += x;
        return ans;
    }
};