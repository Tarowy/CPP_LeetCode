//
// Created by Tarowy on 2023-04-11.
//

/**
 * 700. 二叉搜索树中的搜索
 * https://leetcode.cn/problems/search-in-a-binary-search-tree/
 */
class LeetCode700 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr)
            return nullptr;

        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);

        return root;
    }
};
