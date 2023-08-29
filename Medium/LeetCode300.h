//
// Created by Tarowy on 2023-08-20.
//

#ifndef LEETCODE_LEETCODE300_H
#define LEETCODE_LEETCODE300_H

#include "vector"
#include "iostream"

using namespace std;

/**
 * 300. 最长递增子序列
 * https://leetcode.cn/problems/longest-increasing-subsequence/
 */
class Solution {
public:
    /**
     * 输入：nums = [10,9,2,5,3,7,101,18]
     * 输出：4
     *
     * 输入：nums = [0,1,0,3,2,3]
     * 输出：4
     *
     * dp储存到目前为止的数组元素的最长的子序列
     * dp[i] = max(dp[j]+1,dp[i])
     * j 从 0遍历到i-1 判断j索引的数组元素的最长子序列是否大于i索引的数组当前的最长子序列
     * 如果 dp[j]+1 大于 dp[i] 说明j索引对应的最长子序列长度可以替代i索引的长度，+1是因为要算上i本身
     * 也有可能遇到 nums[i] > nums[j] 但是子序列长度不如j的情况，所以需要用max维持最长长度
     */
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE300_H
