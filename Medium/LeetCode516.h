//
// Created by Tarowy on 2023-08-28.
//

#ifndef LEETCODE_LEETCODE516_H
#define LEETCODE_LEETCODE516_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;


/**
 * 516. 最长回文子序列
 * https://leetcode.cn/problems/longest-palindromic-subsequence/
 */
class Solution {
public:
    /**
     * 输入：s = "bbbab" 输出：4 解释：一个可能的最长回文子序列为 "bbbb"
     * 输入：s = "cbbd" 输出：2 解释：一个可能的最长回文子序列为 "bb"
     *
     * dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]，由于i一直加一，j一直减一，最终i与j会指向同一个元素，回文子串长度必定为1，所以所有的dp[i][i]都要初始化为1
     * 如果s[i]==s[j]，判断[i+1,j-1]的最长回文子序列的长度加上2，因为首位算上之后也能组成回文子序列
     *
     * 如果不相同，则需要删除元素，单独判断只加入i元素或者j元素的最长回文子序列
     * 比如 a<-(i) b b<-(j)  s[i]与s[j]不相同，但bb会组成更长的回文子序列，所以需要删除i元素
     * 1. 删除i元素，判断[i+1,j]的最长回文子序列
     * 2. 删除j元素，判断[i,j-1]的最长回文子序列
     * 取以上两者的最大值 max(dp[i+1][j],dp[i][j-1])
     *
     * 每个dp会继承之前删除元素的状态
     *
     *     b  b  b  a  b      c  b  b  d
     *  b  1  2  3  3  4   c  1  1  2  2
     *  b  0  1  2  2  3   b  0  1  2  2
     *  b  0  0  1  1  3   b  0  0  1  1
     *  a  0  0  0  1  1   d  0  0  0  1
     *  b  0  0  0  0  1
     *
     *
     */
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][s.size() - 1];
    }
};

#endif //LEETCODE_LEETCODE516_H
