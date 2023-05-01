//
// Created by Tarowy on 2023-04-06.
//

using namespace std;
#include "math.h"

/**
 * 111. 二叉树的最小深度
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 */
class LeetCode111 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left != nullptr && root->right == nullptr)
            return minDepth(root->left) + 1;

        if (root->right != nullptr && root->left == nullptr)
            return minDepth(root->right) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
