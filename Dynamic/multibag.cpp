# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

// 多重背包问题
// 多重背包是物品的数量存在限制，可以转换为01背包
// 但是在C++中vector的动态扩容非常耗时，因此最好先计算好vector的维度，再去申请内存
// 最好的方法是，再加一层遍历，去看每一次取几个物品i会比较好

int main() {
    int bagweight, n;
    cin >> bagweight >> n;
    vector<int> weights(n, 0), values(n, 0), nums(n, 0);
    int total_nums = 0;
    for (int i=0; i<n; i++) cin >> weights[i];
    for (int i=0; i<n; i++) cin >> values[i];
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        total_nums += nums[i];
    }

    vector<int> weights1(total_nums), values1(total_nums);
    for (int i=0; i<n; i++) {
        for (int j=0; j<nums[i]; j++) {
            weights1.push_back(weights[i]);
            values1.push_back(values[i]);
        }
    } 

    // 01背包
    vector<int> dp(bagweight+1, 0);
    for (int i=0; i<weights1.size(); i++) {
        for (int j=bagweight; j>=weights1[i]; j--) {
            dp[j] = max(dp[j], dp[j-weights1[i]]+values1[i]);
        }
    }
    return dp[bagweight];
}

int sovle() {
    int bagweight, n;
    cin >> bagweight >> n;
    vector<int> weights(n, 0), values(n, 0), nums(n, 0);
    int total_nums = 0;
    for (int i=0; i<n; i++) cin >> weights[i];
    for (int i=0; i<n; i++) cin >> values[i];
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        total_nums += nums[i];
    }

    vector<int> dp(bagweight+1, 0);
    for (int i=0; i<n; i++) {
        for (int j=bagweight; j>=weights[i]; j--) {
            // 以上为01背包，下面加一层循环，用于判断要取几个物品i
            for (int k=1; k<=nums[i] && j>=k*weights[i]; k++) {
                dp[j] = max(dp[j], dp[j-k*weights[i]] + k*values[i]);
            }
        }
    }
    return dp[bagweight];
}