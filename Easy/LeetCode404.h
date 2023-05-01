//
// Created by Tarowy on 2023-04-09.
//

/**
 * 404. 左叶子之和
 * https://leetcode.cn/problems/sum-of-left-leaves/
 */
class LeetCode404 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int sumOfLeftLeaves(TreeNode *root) {
        int result = 0;

        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr)
                result += root->left->val;
            else
                result += sumOfLeftLeaves(root->left);
        }
        if (root->right != nullptr)
            result += sumOfLeftLeaves(root->right);

        return result;
    }
};
