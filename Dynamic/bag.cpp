# include <vector>
# include <iostream>
using namespace std;

int N, bagweight; // N:物品数量， bagweight：包的容量

int solve() {
    vector<int> weights(N, 0);
    vector<int> values(N, 0);
    for (int i=0; i<N; i++) {
        cin >> weights[i];
    }
    for (int i=0; i<N; i++) {
        cin >> values[i];
    }

    // 初始化dp数组, N*(bagweight+1) 大小
    vector<vector<int>> dp(N, vector<int>(bagweight+1, 0));
    for (int j=weights[0]; j<=bagweight; j++) {
        dp[0][j] = values[0];
    }

    // 物品1， 2， 3...
    for (int i=1; i<N; i++) {
        for (int j=1; j<=bagweight; j++) {
            if (j-weights[i] < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+values[i]);
        }
    }
    return dp[N-1][bagweight];
}

int main() {
    cin >> N >> bagweight;
    int value = solve();
    cout << value;
    return 0;
}