//
// Created by Tarowy on 2023-08-24.
//

#ifndef LEETCODE_LEETCODE1035_H
#define LEETCODE_LEETCODE1035_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 1035. 不相交的线
 * https://leetcode.cn/problems/uncrossed-lines/
 */
class Solution {
public:
    /**
     * 输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]  输出：3
     *
     *  10  5  2  1  5  2
     *      |    /    /
     *      |   /   /
     *  2   5  1  2  5
     *
     *  与1143代码一致，本质上是求顺序相同的最长公共子序列，这样肯定不会相交
     */
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};

#endif //LEETCODE_LEETCODE1035_H
