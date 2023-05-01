//
// Created by Tarowy on 2023-04-11.
//

/**
 * 98. 验证二叉搜索树
 * https://leetcode.cn/problems/validate-binary-search-tree/
 */
class LeetCode98 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    //中序遍历的前一个元素，当前元素必定比前一个元素大
    TreeNode *pre = nullptr;

    /**
     * 按照 左-中-右 的顺序遍历，则遍历二叉树的时候是按照升序的顺序排列的，以此来判断是否符合条件
     * @param root
     * @return        if (root == nullptr)
            return true;

        bool leftValid = isValidBST(root->left);

        if (pre == nullptr || root->val > pre->val) {
            pre = root;
        } else return false;

        bool rightValid = isValidBST(root->right);

        return leftValid && rightValid;
     */
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;

        bool leftValid = isValidBST(root->left);

        if (pre == nullptr || root->val > pre->val) {
            pre = root;
        } else return false;

        bool rightValid = isValidBST(root->right);

        return leftValid && rightValid;
    }
};
