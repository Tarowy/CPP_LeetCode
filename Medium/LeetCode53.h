//
// Created by Tarowy on 2023-05-02.
//
using namespace std;

#include "vector"

/**
 * 53. 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/
 */
class LeetCode53 {
public:
    /**
     * 动态规划解法
     * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4] 输出：6
     *
     * dp[i] = max(dp[i-1]+nums[i],nums[i])
     * dp表示以 包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]
     * dp只能由两种状态推导出来，
     *      1. 前一个dp的最大连续子序列和加上当前元素  dp[i-1]+nums[i]
     *      2. 从当前元素重新计算  nums[i]
     * 从这两种状态中选取最大值
     *
     *       -2  1  -3  4  -1  2  1  -5  4
     *       -2  1  -2  4   3  5  6   1  5
     */
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }


    int maxSubArray1(vector<int> &nums) {
        return getMaxSubArray(nums, 0, nums.size() - 1);
    }

    int getMaxSubArray(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];

        int mid = left + (right - left) / 2;

        //获取左边连续子数组的最大和
        int leftMax = getMaxSubArray(nums, left, mid);
        //获取右边连续子数组的最大和
        int rightMax = getMaxSubArray(nums, mid + 1, right);
        //获取从mid开始向左右两边扩散计算出的最大和
        int crossMax = getCrossMax(nums, left, right);

        /*
         * 从 左边的连续子数组和的最大值
         *    右边连续子数组的和的最大值
         *    左右子数组合并的和的最大值
         * 中筛选出最大值
         */
        return max(crossMax, max(leftMax, rightMax));
    }

    int getCrossMax(vector<int> &nums, int left, int right) {
        int mid = left + (right - left) / 2;

        int leftSum = nums[mid];
        int leftMax = leftSum;

        for (int i = mid - 1; i >= left; --i) {
            leftSum += nums[i];
            leftMax = max(leftSum, leftMax);
        }

        int rightSum = nums[mid + 1];
        int rightMax = rightSum;

        for (int i = mid + 2; i <= right; ++i) {
            rightSum += nums[i];
            rightMax = max(rightSum, rightMax);
        }

        return leftMax + rightMax;
    }
};
