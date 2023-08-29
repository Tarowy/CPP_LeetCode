//
// Created by Tarowy on 2023-08-28.
//

#ifndef LEETCODE_LEETCODE647_H
#define LEETCODE_LEETCODE647_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 647. 回文子串
 * https://leetcode.cn/problems/palindromic-substrings/
 */
class Solution {
public:
    /**
     * 输入：s = "abc" 输出：3 解释：三个回文子串: "a", "b", "c"
     * 输入：s = "aaa" 输出：6 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
     *
     * dp[i][j] 表示从s[i]到s[j]组成的子串是不是回文子串
     *
     * 如果s[i]==s[j]，且dp[i+1][j-1]表示的子串是回文子串，那么dp[i][j]必定也是回文子串
     * 如果s[i]!=s[j]则不用管，因为初始化的时候dp[i][j]本来就是false，而且绝对不会成为回文子串
     *
     * dp[i+1][j-1]是dp[i][j]的左下角，所以遍历的时候应该从下往上，从左到右，这样用到的dp[i+1][j-1]一定都是经过计算的
     *
     * j一定大于i，所以遍历的时候j要从i开始
     *      a  b  b  c (j)      a  a  a (j)
     *   a  o  x  x  x       a  o  o  o
     *   b  x  o  o  x       a  x  o  o
     *   b  x  x  o  x       a  x  x  o
     *   c  x  x  x  o      (i)
     *  (i)
     */
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (auto j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        result++;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = dp[i + 1][j - 1];
                        result++;
                    }
                }
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE647_H
