//
// Created by Tarowy on 2023-07-18.
//

#ifndef LEETCODE_LEETCODE377_H
#define LEETCODE_LEETCODE377_H

#include <vector>
#include <climits>

using namespace std;

/**
 * 377. 组合总和 Ⅳ
 * https://leetcode.cn/problems/combination-sum-iv/
 */
class Solution {
public:
    /**
     * nums = [1,2,3], target = 4  输出：7
     * (1, 1, 1, 1)
     * (1, 1, 2)
     * (1, 2, 1)
     * (1, 3)
     * (2, 1, 1)
     * (2, 2)
     * (3, 1)
     *
     * dp[i] = dp[i] + dp[i-nums[j]]
     * 求组合：先遍历背包容量再遍历物品
     * 求排列：先遍历物品再遍历背包容量
     *
     * 先遍历背包再遍历物品，会让背包容量继承 前一轮容量下 物品的所有选取方式
     * 在前一轮容量下，所有物品都被选过一遍，这一轮容量又会继承前一轮的情况，所以能重复选取
     *    0  1  2  3  4  i
     * 1  1  1  1  2  4
     * 2  X  X  2  3  6
     * 3  X  X  X  4  7
     * j
     */
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] = dp[i] + dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};

#endif //LEETCODE_LEETCODE377_H
