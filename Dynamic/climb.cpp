# include<vector>
# include<iostream>
using namespace std;

// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 所以这是一个全排列的问题
// 先遍历背包，再遍历物品

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int j=1; j<=n; j++) {
        for (int i=1; i<=m; i++) {
            if (j>=i) dp[j] += dp[j-i];
        }
    }
    cout << dp[n] << endl;
}