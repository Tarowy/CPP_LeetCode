//
// Created by Tarowy on 2023-07-02.
//

#ifndef LEETCODE_LEETCODE746_H
#define LEETCODE_LEETCODE746_H

#include <vector>

using namespace std;

/**
 * 746. 使用最小花费爬楼梯
 * https://leetcode.cn/problems/min-cost-climbing-stairs/
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);
        //不上台阶或者只上第一个台阶
        dp[0] = 0;
        dp[1] = 0;

        //cost = [10,15,20]  15
        for (int i = 2; i <= cost.size(); ++i) {
            /*
             * 由于每次只能上一个或两个台阶，所以 n台阶 只与 n-1 和 n-2 台阶有关
             * dp[i]表示达到该台阶所需的最小消费，cost[i]表示i台阶往上爬需要的消费
             */
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp.back();
    }
};

#endif //LEETCODE_LEETCODE746_H
