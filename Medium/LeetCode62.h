//
// Created by Tarowy on 2023-07-03.
//

#ifndef LEETCODE_LEETCODE62_H
#define LEETCODE_LEETCODE62_H

#include <vector>

using namespace std;

/**
 * 62. 不同路径
 * https://leetcode.cn/problems/unique-paths/
 */
class Solution {
public:
    /**
     * 机器人每次只能向右或向下移动，所以每个格子的状态只与左边和上边的格子有关
     * dp[i][j] = dp[i-1][j] + dp[i][j-1] dp[i][j]表示达到 i,j 格子的路径数量
     */
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m,vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

#endif //LEETCODE_LEETCODE62_H
