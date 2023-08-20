//
// Created by Tarowy on 2023-08-08.
//

#ifndef LEETCODE_LEETCODE213_H
#define LEETCODE_LEETCODE213_H

#include <vector>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 213. 打家劫舍 II
 * https://leetcode.cn/problems/house-robber-ii/
 */
class Solution {
public:
    /**
     * 输入：nums = [1,2,3,1]
     * 输出：4
     * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     * 偷窃到的最高金额 = 1 + 3 = 4
     *
     * 由于第一个元素和最后一个元素是挨着的，所以第一个元素和最后一个元素需要分开对待
     * 偷了第一个就不能偷最后一个，偷了最后一个就不能偷第一个
     * 分为两种情况，1. 不包含第一个元素（偷最后一个）  2. 不包含最后一个元素（偷第一个）
     * 比如： 1  2  3  1
     *  1.  2 3 1 不包含第一个元素，
     *  2.  1 2 3 不包含最后一个元素，
     *
     *   0  1  2  3  1
     *      0  1  2  3
     *
     */
    int rob(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        int result1 = robRange(nums, 1, nums.size() - 1); //不偷第一个
        int result2 = robRange(nums, 0, nums.size() - 2); //偷第一个
        return max(result1, result2);
    }

    int robRange(const vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];

        //    1  2  3  1
        //    0  1  2  3
        //       s     e
        // 0  1  2  3  4
        // 0  0  2  0  0
        vector<int> dp(nums.size() + 1, 0);
        dp[start + 1] = nums[start];

        for (int i = start + 1; i <= end; ++i) {
            dp[i + 1] = max(dp[i + 1 - 2] + nums[i], dp[i + 1 - 1]);
        }

        return dp[end + 1];
    }
};

#endif //LEETCODE_LEETCODE213_H
