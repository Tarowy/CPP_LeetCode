//
// Created by Tarowy on 2023-08-13.
//

#ifndef LEETCODE_LEETCODE121_H
#define LEETCODE_LEETCODE121_H

#include <vector>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 121. 买卖股票的最佳时机
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */
class Solution {
public:
    /**
     * 输入：[7,1,5,3,6,4]
     * 输出：5
     * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     *
     * dp[i][0] 表示第i天或者第i天之前就买入了股票 的 持有股票时的最小负债
     * dp[i][1] 表示第i天或者第i天之前就卖出了股票 的 不持有股票时的最大值
     *
     * 买入一个最小的股票，然后再在股票最大时候卖出就能得到最大利润
     * dp[i][0] = max(dp[i-1][0], -prices[i]) 表示是今天之前买入股票负债最小，还是今天买入股票的负债最小
     * dp[i][1] = max(dp[i][0]+prices[i], dp[i-1][1]) 表示是今天之前卖出股票的利润最大，还是今天卖出股票的利润最大
     *
     * dp[0][0]初始化为-prices[0]，表示第一天默认买入股票
     * dp[0][1]初始化为0，表示没有利润
     *
     *           7   1   5   3   6   4
     * dp[i][0] -7  -1  -1  -1  -1  -1
     * dp[i][1]  0   0   4   4   5   5
     */
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }

        return dp[prices.size() - 1][1];
    }
};


#endif //LEETCODE_LEETCODE121_H
