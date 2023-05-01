//
// Created by Tarowy on 2023-04-12.
//
using namespace std;

#include "climits"
#include "math.h"

/**
 * 530. 二叉搜索树的最小绝对差
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
 */
class LeetCode530 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int minDiff = INT_MAX;
    TreeNode *pre = nullptr;

    void traversal(TreeNode *root) {
        if (root == nullptr)
            return;

        //先遍历到最左边
        traversal(root->left);

        if (pre != nullptr)
            minDiff = min(minDiff, root->val - pre->val);

        pre = root;

        traversal(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        traversal(root);
        return minDiff;
    }
};
