//
// Created by Tarowy on 2023-07-04.
//

#ifndef LEETCODE_LEETCODE96_H
#define LEETCODE_LEETCODE96_H

#include <vector>

using namespace std;

/**
 * 96. 不同的二叉搜索树
 * https://leetcode.cn/problems/unique-binary-search-trees/
 */
class LeetCode96 {
public:
    /**
     * dp[n] 表示 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 的种类
     * 每个二叉搜索树与前几种二叉树的种类是有关系的
     * 比如 n = 3
     * 那么就是 dp[左子树节点数为0] * dp[右子树节点数为2] + dp[左子树节点数为2] * dp[右子树节点数为0] + dp[左子树节点数为1] * dp[右子节点树数为1]
     * 即 dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * d[0]
     * @param n
     * @return
     */
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};


#endif //LEETCODE_LEETCODE96_H
