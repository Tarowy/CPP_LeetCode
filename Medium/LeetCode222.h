//
// Created by Tarowy on 2023-04-06.
//
using namespace std;

/**
 * 222. 完全二叉树的节点个数
 * https://leetcode.cn/problems/count-complete-tree-nodes/
 */
class LeetCode222 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;

        TreeNode *left = root->left;
        int leftDepth = 0;

        TreeNode *right = root->right;
        int rightDepth = 0;

        //左子树深度
        while (left != nullptr) {
            leftDepth++;
            left = left->left;
        }

        //右子树深度
        while (right != nullptr) {
            rightDepth++;
            right = right->right;
        }

        //满二叉树特性
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;

        //左右深度不相等，说明该二叉树不是满二叉树
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
