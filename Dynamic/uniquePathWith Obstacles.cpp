#include<vector>
using namespace std;

// 不同路径 II
// 一个机器人位于一个 m x n 网格的左上角
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        
        int flag = 1;
        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0]==1 && flag==1) flag=0;
            dp[i][0] = flag;
        }
        flag = 1;
        for (int j=0; j<n; j++) {
            if (obstacleGrid[0][j] == 1 && flag==1) flag=0;
            dp[0][j] = flag;
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};