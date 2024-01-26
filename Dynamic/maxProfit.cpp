# include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
<<<<<<< HEAD
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
=======
        int ans = 0;
        for (int i=0; i<prices.size(); i++) {
            for (int j=i+1; j<prices.size(); j++) {
                int profit = prices[j] > prices[i] ? prices[j] - prices[i] : 0;
                ans = max(ans, profit);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> prices {7,1,5,3,6,4};
    Solution s;
    int ans = s.maxProfit(prices);
}
>>>>>>> 0868a2953d4e57c3d8920c13eab4eaeb443a2144
