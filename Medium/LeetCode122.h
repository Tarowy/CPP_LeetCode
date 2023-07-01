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
    int maxProfit(vector<int> &prices) {
        int result = 0;

        for (int i = 1; i < prices.size(); ++i) {
            //只添加前后一天差值为正利润时所得的利润
            result += max(prices[i] - prices[i - 1], 0);
        }

        return result;
    }
};
