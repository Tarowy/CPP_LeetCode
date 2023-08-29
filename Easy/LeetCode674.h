//
// Created by Tarowy on 2023-08-21.
//

#ifndef LEETCODE_LEETCODE674_H
#define LEETCODE_LEETCODE674_H

#include "vector"
#include "iostream"

using namespace std;

/**
 * 674. 最长连续递增序列
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 */
class Solution {
public:
    /**
     * nums = [1,3,5,4,7] 输出：3 =>  1,3,5
     * nums = [2,2,2,2,2] 输出：1 => 2
     *
     * if(nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1
     *     1  3  5  4  7        2  2  2  2  2
     *     1  2  3  1  2        1  1  1  1  1
     *
     */
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() <= 1)
            return 1;
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                result = max(dp[i], result);
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE674_H
