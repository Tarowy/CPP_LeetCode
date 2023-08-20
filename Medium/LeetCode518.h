//
// Created by Tarowy on 2023-07-15.
//

#ifndef LEETCODE_LEETCODE518_H
#define LEETCODE_LEETCODE518_H

#include <vector>

using namespace std;

/**
 * 518. 零钱兑换 II
 * https://leetcode.cn/problems/coin-change-ii/
 */
class LeetCode518 {
public:
    /**
     * amount = 5, coins = [1, 2, 5] 输出 4
     * 5=5
     * 5=2+2+1
     * 5=2+1+1+1
     * 5=1+1+1+1+1
     *
     * 2+1+1+1     1+1+1+1 2+2 2+1+1
     * 1+1+1+1+1
     * 2+2+1
     *
     * dp[j] = dp[j] + dp[j-coins[i]] 前面的 dp[j] 表示 从0~i选取硬币 有 多少种方法装满容量 j
     * 后面的 dp[j] 表示不选当前硬币装满容量为j的背包的方法数
     * 正序遍历，表示一个硬币可以重复选取多次
     *
     *    0  1  2  3  4  5
     * 1  1  1  1  1  1  1
     * 2  1  1  2  2  3  3
     * 5  1  1  2  2  4  4
     */
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (const int &coin: coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] = dp[j] + dp[j - coin];
            }
        }

        return dp[amount];
    }
};


#endif //LEETCODE_LEETCODE518_H
