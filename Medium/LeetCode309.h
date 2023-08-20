//
// Created by Tarowy on 2023-08-17.
//

#ifndef LEETCODE_LEETCODE309_H
#define LEETCODE_LEETCODE309_H

using namespace std;

#include "vector"
#include "iostream"

/**
 * 309. 买卖股票的最佳时机含冷冻期
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */
class Solution {
public:
    /**
     * 输入: prices = [1,2,3,0,2]
     * 输出: 3
     * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
     *
     * 冷冻期需要考虑前一天卖出的情况
     * dp[i][0]+prices[i] 表示今天卖出
     * dp[i-1][1] 表示昨天以及昨天之前卖出的话拥有的金额
     *
     * dp[i - 1][0] 今天不买入，说明昨天或昨天之前卖出了，保持之前的持股状态的金额
     * dp[i-2][1]-prices[0] 今天买入，说明至少昨天没卖出，就不能用昨天卖出的金额计算，得到买入后持股状态的金额
     * dp[i-1][0]+prices[i] 如果昨天没卖出，那么今天就可以卖出，使用dp[i-1][0]是因为不会在同一天买入又卖出股票，那相当于什么也没做
     * dp[i-1][1] 如果是昨天卖出的，今天无法操作，保持昨天的金额
     * 买入和卖出是有关联的，卖出时会依赖昨天的持股状态
     *
     *                                              如果昨天没卖出，根据昨天的状态买入或卖出  如果昨天卖出，冷冻期，所有状态继承昨天的
     *      1  2  5  0  2       1  2  5    dp[i][0] = max( dp[i - 2][1] - prices[i], |  dp[i - 1][0])
     *     -1 -1 -1  1  2      -1 -1 -1    dp[i][1] = max( dp[i - 1][0] + prices[i], |  dp[i - 1][1])
     *      0  1  4  4  4       0  1  4
     *
     *      1  2  3  0  2
     *     -1 -1 -1  1  1
     *      0  1  2  1  3
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        vector <vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[1][0] + prices[1], dp[0][1]);

        for (int i = 2; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 2][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }

        return dp[prices.size() - 1][1];
    }
};

#endif //LEETCODE_LEETCODE309_H
