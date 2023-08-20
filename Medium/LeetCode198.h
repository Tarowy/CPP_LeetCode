//
// Created by Tarowy on 2023-08-07.
//

#ifndef LEETCODE_LEETCODE198_H
#define LEETCODE_LEETCODE198_H

#include <vector>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 198. 打家劫舍
 * https://leetcode.cn/problems/house-robber/
 */
class Solution {
public:
    /**
     * 输入：[2,7,9,3,1]
     * 输出：12
     * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     * 偷窃到的最高金额 = 2 + 9 + 1 = 12
     *
     * 比较 偷当前房屋的最大价值 和 不偷当前房屋的最大价值 谁更大
     * 当前房屋要偷，那么前一个房屋不能偷，需要看前前个房屋(dp[i-2])的最大价值加上当前房屋的价值；
     * 当前房屋不偷，那么前一个房屋就被偷了，需要看前一个房屋(dp[i-1])的最大价值
     * dp[i] = max(dp[i-2]+nums[i],dp[i-1])
     * dp表示从 房间0偷到房间i 的最大价值
     *
     *    0  1  2  3  4  5
     *    0  2  7  9  3  1
     *       2  7 11 11  12
     */
    int rob(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i + 1] = max(dp[i + 1 - 2] + nums[i], dp[i + 1 - 1]);
        }

        return dp[nums.size()];
    }
};

#endif //LEETCODE_LEETCODE198_H
