# 背包问题的递推公式
```cpp
dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
```

# 求装满背包有几种方法，组合问题
```cpp
dp[0] = 1;
dp[j] += dp[j-weight[i]];
```

# 01背包的顺序
```cpp
for(int i=0; i<nums.size(); i++) {
    for (int j=bagweight; j>=nums[i]; j--)
}
```

# 完全背包的顺序
完全背包j从0到bagweight
```cpp
for (int i=0; i<nums.size(); i++) {
    for (int j=nums[i]; j<=bagweight; j++)
}
```

**如果求组合数就是外层for循环遍历物品，内层for遍历背包。**

**如果求排列数就是外层for遍历背包，内层for循环遍历物品。**
