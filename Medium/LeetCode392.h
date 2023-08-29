//
// Created by Tarowy on 2023-08-25.
//

#ifndef LEETCODE_LEETCODE392_H
#define LEETCODE_LEETCODE392_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 392. 判断子序列
 * https://leetcode.cn/problems/is-subsequence/description/
 */
class Solution {
public:
    /**
     * 输入：s = "abc", t = "ahbgdc" 输出：true
     * 输入：s = "axc", t = "ahbgdc" 输出：false
     *
     * 类似1149题，但这次只有一个数组元素能被删除
     * dp[i][j]表示 s的0~j的字符 与 t的0~i的字符 的相同子序列的长度
     * 判断s是不是t的子序列，可以删除t中的元素，但不能删除s的元素 dp[i-1][j]
     * 比较 s[i-1] 与 s[j-1] （dp的两个维度都比原数组多了一位，所以这里的索引要减去1）:
     * 相同，这时候就可以删除s的元素，得到 0~j-2 与 0~i-2 的相同子序列的长度 并+1
     * 不相同，删除t的元素，得到 0~j-1 与 0~i-2 的相同子序列的长度
     *       a  h  b  g  d  c (t)
     *    0  0  0  0  0  0  0
     *  a 0  1  1  1  1  1  1
     *  b 0  0  0  2  2  2  2
     *  c 0  0  0  0  0  0  3
     * (s)
     *
     */
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[t.size()][s.size()] == s.size();
    }
};

#endif //LEETCODE_LEETCODE392_H
