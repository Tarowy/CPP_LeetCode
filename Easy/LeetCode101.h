//
// Created by Tarowy on 2023-04-05.
//
using namespace std;

/**
 * 101. 对称二叉树
 * https://leetcode.cn/problems/symmetric-tree/
 */
class LeetCode101 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return false;
        return treeCompare(root->left,root->right);
    }

    bool treeCompare(TreeNode *left, TreeNode *right) {
        //如果以下条件均通过，说明左右节点相等
        if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;
        else{
            //后序遍历，先比较子节点，最后比较自身节点
            bool outside = treeCompare(left->left,right->right);
            bool inside = treeCompare(left->right,right->left);
            //返回左右节点的比较结果
            return outside && inside;
        }
    }
};
