//
// Created by Tarowy on 2023-04-09.
//

/**
 * 112. 路径总和
 * https://leetcode.cn/problems/path-sum/
 */
class LeetCode112 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum - root->val == 0;
        }

        //递归的时候直接传入相减的值，避免根节点本身就等于targetSum
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
