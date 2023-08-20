//
// Created by Tarowy on 2023-07-04.
//

#ifndef LEETCODE_LEETCODE343_H
#define LEETCODE_LEETCODE343_H

#include <vector>

using namespace std;

/**
 * 343. 整数拆分
 * https://leetcode.cn/problems/integer-break/
 */
class Solution {
public:
    /**
     * dp[i] 表示 i 这个数拆分后所获得的最大乘积，由于是拆分，所以 i 至少是拆分成两个数的
     *
     * 输入: n = 10
     * 输出: 36
     * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
     *
     * @param n
     * @return
     */
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            //数学定理：拆分一个数 n 使之乘积最大，那么一定是拆分成 m 个近似相同的子数相乘才是最大的，所以顶多循环到 n 的一半就可以了
            for (int j = 1; j <= static_cast<int>(i * 0.5f); ++j) {
                /*
                 * 不需要拆分j，由于拆分j会至少拆成两个数，导致dp[j] * dp[i-j] 会被至少拆成四个数相乘
                 * j * (i - j) 是只拆分成两个数
                 * j * dp[i - j] 是拆分成至少三个数
                 * 所以这两种情况需要分开判断，比如 4 会有 1*dp[3], 2*dp[2], 3*dp[1] 都是拆分成三个数的
                 * 但是它最大的乘积只需要拆成两个数即 2*2，所以还需要加上只拆成两个数的情况
                 */
                dp[i] = max(j * (i - j), max(j * dp[i - j], dp[i]));
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_LEETCODE343_H
