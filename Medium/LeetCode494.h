//
// Created by Tarowy on 2023-07-07.
//

#ifndef LEETCODE_LEETCODE494_H
#define LEETCODE_LEETCODE494_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * 494. 目标和
 * https://leetcode.cn/problems/target-sum/
 */
class Solution {
public:
    /**
     * nums = [1,1,1,1,1], target = 3
     *   -1 + 1 + 1 + 1 + 1 = 3
     *   +1 - 1 + 1 + 1 + 1 = 3
     *   +1 + 1 - 1 + 1 + 1 = 3
     *   +1 + 1 + 1 - 1 + 1 = 3
     *   +1 + 1 + 1 + 1 - 1 = 3
     *
     * 将所有数分成正数的集合 left 和负数的集合 right，注意负数集合还没真正添加负号
     * 那么就有 left + right = sum (正数集合与负数集合的总和)   left - right = target (为负数集合添加负号，整数集合与负数集合的差值就是target)
     * 可以得出 2*left = sum + target => left = (sum + target) / 2  如果left算出来是小数，那说明无法得到target，直接返回0
     *
     *  left = (3+5)/2 = 4 即任意选或不选所有元素，能凑成4的方法有多少种，left只考虑nums[i]相加的情况
     *
     * dp[j] 表示从 nums[0]~nums[i] 中任意选或者不选元素，有多少方法使和为 j
     * dp[j] = dp[j] + dp[j - nums[i]]
     * 等式后面的 dp[j] 表示不选 nums[i] 有多少种方法得到 j
     * dp[j - nums[i]] 表示选上 dp[j] 又多少种方法得到 j
     *
     *    0  1  2  3  4
     * 1  1  1  0  0  0
     * 1  1  2  1  0  0
     * 1  1  3  3  1  0
     * 1  1  4  6  4  1
     * 1  1  5 10 10  5
     *
     */
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (const int &num: nums)
            sum += num;

        if (abs(target) > sum || (sum + target) % 2 == 1)
            return 0;

        int left = static_cast<int>(static_cast<float>((sum + target)) * 0.5f);

        vector<int> dp(left + 1, 0);
        dp[0] = 1; //为了公式，dp[0]只能初始化成1

        for (const int &num: nums) {
            for (int j = left; j >= num; --j) {
                dp[j] = dp[j] + dp[j - num];
            }
        }

        return dp[left];
    }
};

#endif //LEETCODE_LEETCODE494_H
