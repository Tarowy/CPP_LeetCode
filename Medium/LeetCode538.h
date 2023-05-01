//
// Created by Tarowy on 2023-04-20.
//

/**
 * 538. 把二叉搜索树转换为累加树
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/
 */
class LeetCode538 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *pre = nullptr;

    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr)
            return nullptr;

        root->right = convertBST(root->right);

        if (pre != nullptr)
            root->val += pre->val;
        pre = root;

        root->left = convertBST(root->left);

        return root;
    }
};
