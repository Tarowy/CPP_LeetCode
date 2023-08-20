//
// Created by Tarowy on 2023-08-09.
//

#ifndef LEETCODE_LEETCODE337_H
#define LEETCODE_LEETCODE337_H

#include <vector>
#include <climits>
#include <string>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 337. 打家劫舍 III
 * https://leetcode.cn/problems/house-robber-iii/
 */
class Solution {
public:
    /**
     * 输入: root = [3,2,3,null,3,null,1]
     * 输出: 7
     * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
     *
     * 使用后序遍历从最底部到顶部
     * 每个节点拥有两种状态，偷与不偷，子节点偷了父节点就不能偷，否则就可以偷父节点
     * 子节点同时储存偷与不偷所得到的最大价值，dp[0]表示不偷，dp[1]表示偷
     */
    int rob(TreeNode *root) {
        if (root == nullptr)
            return 0;
        vector<int> value = robTree(root);
        return max(value[0], value[1]);
    }

    vector<int> robTree(TreeNode *root) {
        if (root == nullptr)
            return {0, 0};
        // dp[0]表示不偷，dp[1]表示偷
        vector<int> dp(2, 0);
        // 左子树的最大价值
        vector<int> left_value = robTree(root->left);
        // 右子树的最大价值
        vector<int> right_value = robTree(root->right);

        // 偷当前节点，那么左右子树不能偷，取他们不偷的价值
        int rob_value = root->val + left_value[0] + right_value[0];
        // 不偷当前节点，那么左右子树可以偷也可以不偷，取他们的最大价值
        int no_rob_value = max(left_value[0], left_value[1]) + max(right_value[0], right_value[1]);

        return {no_rob_value, rob_value};
    }
};

#endif //LEETCODE_LEETCODE337_H
