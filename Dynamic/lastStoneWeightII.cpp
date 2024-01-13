# include<vector>
# include<algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 是一种分割子集的问题，能够将石头分成一样重的两堆？
        // 背包的容量为stones.sum() / 2
        int total_weight = 0, bagweight=0;
        for (int i=0; i<stones.size(); i++) {
            total_weight += stones[i];
        }
        bagweight = total_weight / 2;
        vector<int> dp(bagweight+1, 0);
        for (int i=0; i<stones.size(); i++) {
            for (int j=bagweight; j>=stones[i]; j--) {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return abs(dp[bagweight] - (total_weight-dp[bagweight]));
    }
};