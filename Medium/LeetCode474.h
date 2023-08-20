//
// Created by Tarowy on 2023-07-09.
//

#ifndef LEETCODE_LEETCODE474_H
#define LEETCODE_LEETCODE474_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * 474. 一和零
 * https://leetcode.cn/problems/ones-and-zeroes/
 */
class Solution {
public:
    /**
     * strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
     *
     * dp[m][n] m表示只能装'1'的维度的最大容量，n表示只能装'0'的维度的最大容量
     * dp[m][n] 表示尽量装满维度'1'和维度'0'的最大子集长度
     *
     * dp[m][n] = max(dp[m][n], dp[m - str[i].oneNums][n - str[i].zeroNums] + 1)
     * 等式右边的 dp[m][n] 表示不选strs[i]只选 0~i 的strs能尽量装满 m,n 所需的最大子集长度
     * dp[m - str[i].oneNums][n - str[i].zeroNums] ：
     *     表示要选strs[i]，为strs[i]预留出空间，余下的空间任意选或不选 0~i-1 的strs能尽量装满 m,n 所需的最大子集长度
     * 最后加一是因为要选当前的数，所以子集长度加一
     *
     * ["10", "0", "1"], m = 1, n = 1
     *
     *        10  0  1
     *  one    1  0  1
     *  zero   1  1  0
     *
     * init:      “10” 1,1   “0” 0,1
     *    0  1       0  1       0  1
     * 0  1  1    0  1  1    0  1  1
     * 1  1  0    1  1  1    1  1  2
     *
     *         10 0001 111001 1 0
     *  zero   1   3    2     0 1
     *  one    1   1    4     1 0
     *
     * init:
     *     0  1  2  3  4  5
     *  0  1  1  1  1  1  1
     *  1  1  0  0  0  0  0
     *  2  1  0  0  0  0  0
     *  3  1  0  0  0  0  0
     *
     *  “10”：  1,1           “0001”：  1,3           “1”：  1,0
     *    0  1  2  3  4  5       0  1  2  3  4  5       0  1  2  3  4  5
     * 0  1  1  1  1  1  1    0  1  1  1  1  1  1    0  1  1  1  1  1  1
     * 1  1  1  1  1  1  1    1  1  1  1  1  1  1    1  1  1  1  1  1  1
     * 2  1  1  1  1  1  1    2  1  1  1  1  1  1    2  1  1  1  1  1  1
     * 3  1  1  1  1  1  1    3  1  2  2  2  2  2    3  1  2  2  2  2  2
     *
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int zero_nums, one_nums;

        for (auto &str: strs) {
            zero_nums = 0;
            one_nums = 0;
            for (auto &c: str) {
                if (c == '0')
                    zero_nums++;
                else
                    one_nums++;
            }

            for (int x = m; x >= zero_nums; --x) {
                for (int y = n; y >= one_nums; --y) {
                    dp[x][y] = max(dp[x][y], dp[x - zero_nums][y - one_nums] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

#endif //LEETCODE_LEETCODE474_H
