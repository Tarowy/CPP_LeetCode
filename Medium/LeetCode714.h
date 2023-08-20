//
// Created by Tarowy on 2023-08-20.
//

#ifndef LEETCODE_LEETCODE714_H
#define LEETCODE_LEETCODE714_H

using namespace std;

#include "vector"
#include "iostream"

/**
 * 714. 买卖股票的最佳时机含手续费
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */
class Solution {
public:
    /**
     * 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
     * 输出：8
     * 在此处买入 prices[0] = 1
     * 在此处卖出 prices[3] = 8
     * 在此处买入 prices[4] = 4
     * 在此处卖出 prices[5] = 9
     * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
     *
     * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]) 持有股票时的最大金额
     * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - 2) 不持有股票时的最大金额
     *
     *        1  3  2  8  4  9
     *       -1 -1 -1 -1  1  1
     *        0  0  0  5  5  8
     */
    int maxProfit(vector<int>& prices, int fee) {
        vector <vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }

        return dp[prices.size() - 1][1];
    }
};

#endif //LEETCODE_LEETCODE714_H
