//
// Created by Tarowy on 2023-07-03.
//

#ifndef LEETCODE_LEETCODE63_H
#define LEETCODE_LEETCODE63_H

#include <vector>

using namespace std;

/**
 * 63. 不同路径 II
 * https://leetcode.cn/problems/unique-paths-ii/
 */
class Solution {
public:
    /**
     * dp[i][j] = dp[i-1][j] + dp[i][j-1]
     * 类似于62题，如果有障碍物的话，路径就是0
     */
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        auto rowSize = obstacleGrid.size();
        auto columnSize = obstacleGrid[0].size();

        vector <vector<int>> dp(rowSize, vector<int>(columnSize));
        dp[0][0] = !obstacleGrid[0][0];

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (i == 0 && j == 0)
                    continue;

                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rowSize - 1][columnSize - 1];
    }
};

#endif //LEETCODE_LEETCODE63_H
