//
// Created by Tarowy on 2023-08-27.
//

#ifndef LEETCODE_LEETCODE72_H
#define LEETCODE_LEETCODE72_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 72. 编辑距离
 * https://leetcode.cn/problems/edit-distance/
 */
class Solution {
public:
    /**
     * 输入：word1 = "horse", word2 = "ros" 输出：3
     * 解释：horse -> rorse (将 'h' 替换为 'r')  rorse -> rose (删除 'r')  rose -> ros (删除 'e')
     *
     * 输入：word1 = "intention", word2 = "execution" 输出：5
     * 解释： intention -> inention (删除 't')  inention -> enention (将 'i' 替换为 'e')  enention -> exention (将 'n' 替换为 'x')
     * exention -> exection (将 'n' 替换为 'c')  exection -> execution (插入 'u')
     *
     * 如果word1[i]与word2[j]不相等
     * 1. 删除一个元素，不管当前i元素，看看0~i-1的元素变成word2的步数
     *      dp[i-1][j]+1
     * 2. 插入一个元素，因为必定插入的是与j相同的元素，所以只需要看0~i的元素变成0~j-1的元素需要的步数
     *      dp[i][j-1]+1
     * 3. 改变一个元素，则先不管当前元素，看看0~i-1的元素变成0~j-1的元素的步数
     *      dp[i-1][j-1] + 1
     *
     * 如果word1[i]与word2[j]相等，直接延续dp[i-1][j-1]
     *
     *
     *          h  o  r  s  e (1)
     *       0  1  2  3  4  5
     *    r  1  1  2  2  3  4
     *    o  2  2  1  2  3  4
     *    s  3  3  2  2  2  3
     *   (2)
     */
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j) dp[0][j] = j;

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

#endif //LEETCODE_LEETCODE72_H
