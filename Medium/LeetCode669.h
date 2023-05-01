//
// Created by Tarowy on 2023-04-17.
//

/**
 * 669. 修剪二叉搜索树
 * https://leetcode.cn/problems/trim-a-binary-search-tree/
 */
class LeetCode669 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr)
            return nullptr;

        //所有左子树都小于根节点，根节点比low还小，那么左子树也都比low小，舍弃左子树
        if (root->val < low)
            return trimBST(root->right,low,high);

        //所有右子树都大于根节点，根节点比high还大，那么右子树也都比high大，舍弃右子树
        if (root->val > high)
            return trimBST(root->left,low,high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
