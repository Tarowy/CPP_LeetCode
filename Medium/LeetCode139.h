//
// Created by Tarowy on 2023-07-31.
//

#ifndef LEETCODE_LEETCODE139_H
#define LEETCODE_LEETCODE139_H

#include <vector>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 139. 单词拆分
 * https://leetcode.cn/problems/word-break/
 */
class Solution {
public:
    /**
     * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
     * 输出: true
     *
     * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
     * 输出: false
     *
     * dp[i] 储存的是背包容量为i的情况下能达到匹配要求的单词
     *    0  1  2  3  4  5  6  7  8 9
     *    O  X  X  O  O  X  X  O  X X
     */
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> word_set(wordDict.cbegin(), wordDict.cend());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                // j到i的单词符合匹配要求，且0-j的单词也符合匹配要求，那么当前背包容量也同样符合匹配要求
                if (word_set.find(word) != word_set.end() && dp[j])
                    dp[i] = true;
            }
        }

        return dp[s.size()];
    }
};

#endif //LEETCODE_LEETCODE139_H
