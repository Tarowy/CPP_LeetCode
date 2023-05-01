//
// Created by Tarowy on 2023-04-02.
//
using namespace std;

#include "vector"
#include "stack"
#include "algorithm"

/**
 * 145. 二叉树的后序遍历
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/
 */
class LeetCode145 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack < TreeNode * > treeStack;
        TreeNode *cur = root;

        treeStack.push(cur);
        //会得到 根-右-左 的顺序，反转后就是左右根
        while (!treeStack.empty()) {
            cur = treeStack.top();
            treeStack.pop();
            result.push_back(cur->val);

            if (cur->left != nullptr)
                treeStack.push(cur->left);
            if (cur->right != nullptr)
                treeStack.push(cur->right);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};