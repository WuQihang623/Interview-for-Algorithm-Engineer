# include<vector>
# include<iostream>
using namespace std;

// 完全背包问题，物品数量有无数个

int main() {
    int n, bagweight;
    cin >> n >> bagweight;
    vector<int> weights(n, 0);
    vector<int> values(n, 0);
    for (int i=0; i<n; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<int> dp(bagweight+1, 0);
    for (int i=0; i<n; i++) {
        // 01背包内嵌的循环是从大到小遍历，为了保证每个物品仅被添加一次。
        // 完全背包的物品是可以添加多次的，所以要从小到大去遍历
        for (int j=weights[i]; j<=bagweight; j++) {
            dp[j] = max(dp[j], dp[j-weights[i]]+values[i]);
        }
    }
    cout << dp[bagweight];
    return dp[bagweight];
}