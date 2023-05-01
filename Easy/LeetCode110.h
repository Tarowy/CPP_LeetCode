//
// Created by Tarowy on 2023-04-07.
//
using namespace std;

#include "math.h"

/**
 * 110. 平衡二叉树
 * https://leetcode.cn/problems/balanced-binary-tree/
 */
class LeetCode110 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    bool isBalanced(TreeNode *root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode *root) {
        if (root == nullptr)
            return 0;

        //如果左右子树任意一方的高度返回-1都说明该树不是平衡二叉树
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;

        //计算左右子树的高度差，如果大于1则直接返回失败结果，否则返回最大高度
        if (abs(leftHeight - rightHeight) > 1) return -1;
        else return max(leftHeight, rightHeight) + 1;
    }
};
