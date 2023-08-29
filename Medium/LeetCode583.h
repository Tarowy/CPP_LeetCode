//
// Created by Tarowy on 2023-08-26.
//

#ifndef LEETCODE_LEETCODE583_H
#define LEETCODE_LEETCODE583_H

#include "vector"
#include "iostream"
#include "string"

using namespace std;

/**
 * 583. 两个字符串的删除操作
 * https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 */
class Solution {
public:
    /**
     * 输入: word1 = "sea", word2 = "eat" 输出: 2
     * 输入：word1 = "leetcode", word2 = "etco" 输出：4
     *
     * dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数
     * 如果 word1[i] 与 word2[j] 不相同
     * 1. 删除i的元素，dp[i][j]等于dp[i-1][j]的删除数+1
     * 2. 删除j的元素，dp[i][j]等于dp[i][j-1]的删除数+1
     * 3. i和j的元素都删除，dp[i][j]等于dp[i-1][j-1]的删除数+2，因为这里删除了两个元素
     *
     * 如果 word1[i] 与 word2[j] 相同，就不用删除元素，保留dp[i-1][j-1]的结果
     *
     *         s  p  a  k  e
     *      0  1  2  3  4  5
     *    p 1  2  1
     *    a 2  3  2
     *    r 3  4  3
     *    k 4  5  4
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
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

#endif //LEETCODE_LEETCODE583_H
