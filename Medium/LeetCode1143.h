//
// Created by Tarowy on 2023-08-22.
//

#ifndef LEETCODE_LEETCODE1143_H
#define LEETCODE_LEETCODE1143_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 1143. 最长公共子序列
 * https://leetcode.cn/problems/longest-common-subsequence/
 */
class Solution {
public:
    /**
     * 输入：text1 = "abcde", text2 = "ace"   输出：3
     *
     * dp[i][j]表示 text1的0~i的字符 与 text2的0~j的字符 的最长公共子序列的长度
     * 当a与a、ac、ace比较时，他们的 最大公共子序列长度都是1，即a，所以每次比较会保留之前的状态
     * 当i与j的字符相同，比如abc与ac比较时，c相同，那么去掉c，比较 ab与a的最长公共子序列的长度再加1 就是 当前的公共子序列长度
     * 当i与j的字符不相同，比如abc与ace比较时，需要对比 abc与ac(dp[i][j-1]) 和 ab与ace(dp[i-1][j]) 的最长公共子序列的长度，即 保留以前字符的状态
     *
     *         a  b  c  d  e        y  b  y
     *      0  0  0  0  0  0     0  0  0  0
     *   a  0  1  1  1  1  1   b 0  0  1  1    yby与b比较时，还需要考虑 yb与b(删除i中的元素) 的公共子序列  dp[i - 1][j]
     *   c  0  1  1  2  2  2   l 0  0  1  1    yb与bl比较时，还需要考虑 yb与b(删除j中的元素) 的公共子序列  dp[i][j - 1]
     *   e  0  1  1  2  2  3
     */
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

#endif //LEETCODE_LEETCODE1143_H
