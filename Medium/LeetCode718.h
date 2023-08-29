//
// Created by Tarowy on 2023-08-21.
//

#ifndef LEETCODE_LEETCODE718_H
#define LEETCODE_LEETCODE718_H

#include "vector"
#include "iostream"

using namespace std;

/**
 * 718. 最长重复子数组
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
 */
class Solution {
public:
    /**
     * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7] 输出：3  [3,2,1]
     * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0] 输出：5
     *
     * dp[i][j] = dp[i-1][j-1] + 1 dp表示(i-1,j-1)为止的最长公共子数组个数
     * dp[i][j]的状态只与 i-1,j-1 有关，所以可以压缩dp的空间，需要从后往前遍历，防止数据覆盖
     * 需要多增加一列，因为dp[0][0]的时候会溢出
     *              1  2  3  2  1  nums1
     *           0  0  0  0  0  0
     *        3  0  0  0  1  0  0
     *        2  0  0  1  0  2  0
     *        1  0  1  0  0  0  3
     *        4  0  0  0  0  0  0
     *        7  0  0  0  0  0  0
     *      nums2
     *
     */
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;

        for (int i = 1; i <= nums1.size(); ++i) {
            for (unsigned long long j = nums2.size(); j > 0; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE718_H
