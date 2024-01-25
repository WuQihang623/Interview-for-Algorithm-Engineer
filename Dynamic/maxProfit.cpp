# include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
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