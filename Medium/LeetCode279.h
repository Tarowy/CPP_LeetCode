//
// Created by Tarowy on 2023-07-31.
//

#ifndef LEETCODE_LEETCODE279_H
#define LEETCODE_LEETCODE279_H

#include <vector>
#include <climits>

using namespace std;

/**
 * 279. 完全平方数
 * https://leetcode.cn/problems/perfect-squares/
 */
class Solution {
public:
    /**
     * 输入：n = 12
     * 输出：3
     * 解释：12 = 4 + 4 + 4
     *
     * 输入：n = 13
     * 输出：2
     * 解释：13 = 4 + 9
     *
     *     0  1  2  3  4
     *  1  0  1  2  3  4
     *  4  X  X  X  X  1
     *  9  X  X  X  X  X
     */
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j * j <= n; j++) {
                if (j * j > i) break;
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_LEETCODE279_H
