# include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==1) return 0;
        vector<int> dp(prices.size(), 0);
        for (int i=1; i<prices.size(); i++) {
            dp[i] = prices[i] - prices[i-1];
        }
        int profit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (dp[i] > 0) profit+=dp[i];
        }
        return profit;
    }
};