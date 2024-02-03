# 背包问题
## 背包问题的递推公式
```cpp
// 问能否装满背包，或者最多装多少
dp[j] = max(dp[j], dp[j-weight[i]]+weight[i]);
// 装满背包有几种方法
dp[0] = 1;
dp[j] += dp[j-nums[i]]
// 装满背包最大价值
dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
// 装满背包所需的物品最小个数
vector<int> dp(bagweight, INT_MAX);
dp[j] = min(dp[j], dp[j-weight[i]]+1);
```


## 01背包的顺序
```cpp
// 只能先遍历物品再遍历背包，且背包是从大到小遍历
for(int i=0; i<nums.size(); i++) {
    for (int j=bagweight; j>=nums[i]; j--)
}
```

## 完全背包的顺序
```cpp
// 先遍历背包还是物品都是可以的，第二层for循环是由小到大
//如果是求组合数就是外层遍历物品，内层遍历背包
// 如果是求排列数就是外层遍历背包，内层遍历物品
for (int i=0; i<nums.size(); i++) {
    for (int j=nums[i]; j<=bagweight; j++)
}

for (int i=1; i<=bagweight; i++) {
    for (int j=0; j<nums.size(); j++) {
        
    }
}
```

# 子序列问题
## 子序列

## 子数组

## 编辑距离

