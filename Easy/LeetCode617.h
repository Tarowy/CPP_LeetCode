//
// Created by Tarowy on 2023-04-11.
//

/**
 * 617. 合并二叉树
 * https://leetcode.cn/problems/merge-two-binary-trees/
 */
class LeetCode617 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {

        if (root1 == nullptr)
            return root2;

        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
