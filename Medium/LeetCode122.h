//
// Created by Tarowy on 2023-05-02.
//
using namespace std;

#include "vector"

/**
 * 122. 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 */
class LeetCode122 {
public:
    /**
     * 动态规划解法
     * 输入：prices = [7,1,5,3,6,4]
     * 输出：7
     *
     * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]) 持有股票时的最大金额
     * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]) 不持有股票时的最大金额
     *
     * 先挑买入股票后剩余价钱最多的那天买入，再在卖出能获得利润的那天卖出，参考贪心算法
     * 买入股票需要考虑卖出股票后剩余的价钱
     * dp[i][0] 是今天买股票还是今天之前买股票所持有的金额最大
     * dp[i][1] 是今天卖股票还是今天之前卖股票所持有的金额最大
     * dp[i][1]依赖于dp[i][0]，想要dp[i][1]最大，就得保证dp[i][0]也最大
     *
     *           7   1   5   3   6   4       1  4  6
     * dp[i][0] -7  -1  -1   1   1   3      -1 -1 -1
     * dp[i][1]  0   0   4   4   7   7       0  3  5
     *
     *           7   1   5   3   2   4
     * dp[i][0] -7  -1  -1   1   2   2
     * dp[i][1]  0   0   4   4   4   6
     */
    int maxProfit(vector<int> &prices) {
        vector <vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }

        return dp[prices.size() - 1][1];
    }


    /**
     * 贪心解法
     */
    int maxProfit1(vector<int> &prices) {
        int result = 0;

        for (int i = 1; i < prices.size(); ++i) {
            //只添加前后一天差值为正利润时所得的利润
            result += max(prices[i] - prices[i - 1], 0);
        }

        return result;
    }
};
