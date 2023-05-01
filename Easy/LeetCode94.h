//
// Created by Tarowy on 2023-04-02.
//
using namespace std;

#include "vector"
#include "stack"

/**
 * 94. 二叉树的中序遍历
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/
 */
class LeetCode94 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack < TreeNode * > treeStack;
        TreeNode *cur = root;

        if (root == nullptr)
            return result;

        while (cur != nullptr || !treeStack.empty()) {
            //取出元素时获取其值
            if (cur == nullptr) {
                cur = treeStack.top();
                treeStack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                treeStack.push(cur);
                cur = cur->left;
            }
        }

        return result;
    }
};
