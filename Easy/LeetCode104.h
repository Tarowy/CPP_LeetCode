//
// Created by Tarowy on 2023-04-06.
//
using namespace std;
#include "math.h"

/**
 * 104. 二叉树的最大深度
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 */
class LeetCode104 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
