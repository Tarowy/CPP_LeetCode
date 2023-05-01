//
// Created by Tarowy on 2023-04-15.
//

/**
 * 235. 二叉搜索树的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
class LeetCode235 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    /**
     * 当根节点的值在p和q区间内的时候那么该节点就是p和q的公共父节点
     * @param root
     * @param p
     * @param q
     * @return
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;

        if ((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        return nullptr;
    }
};
