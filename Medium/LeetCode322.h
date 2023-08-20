//
// Created by Tarowy on 2023-07-30.
//

#ifndef LEETCODE_LEETCODE322_H
#define LEETCODE_LEETCODE322_H

#include <vector>
#include <climits>

using namespace std;

/**
 * 322. 零钱兑换
 * https://leetcode.cn/problems/coin-change/description/
 */
class LeetCode322 {
public:
    /**
     * 输入：coins = [1, 2, 5], amount = 11
     * 输出：3
     * 解释：11 = 5 + 5 + 1
     * 比如想凑成3，可以2+1也可以1+2所以是组合
     * 先遍历背包再遍历物品
     *
     * 每个都初始化为无穷大，表示需要无穷个硬币，为了公式dp[0]=0
     * dp[i] = min(dp[i],dp[i-coins[j]+1)
     *
     *    0  1  2  3  4  5
     * 1  0  1  2  2  3  3
     * 2  X  X  1  2  2  3
     * 5  X  X  X  X  X  1
     *
     *     0 1 2 3
     *  2  0 X 1
     */
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                // 由于不是按从小到大排列的，所以不能break
                if (coins[j] > i || dp[i - coins[j]] == INT_MAX)
                    continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};


#endif //LEETCODE_LEETCODE322_H
