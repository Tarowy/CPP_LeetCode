//
// Created by Tarowy on 2023-04-15.
//

/**
 * 701. 二叉搜索树中的插入操作
 * https://leetcode.cn/problems/insert-into-a-binary-search-tree/
 */
class LeetCode701 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left,val);

        if (val > root->val)
            root->right = insertIntoBST(root->right,val);

        return root;
    }
};
