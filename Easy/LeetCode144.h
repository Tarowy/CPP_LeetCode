//
// Created by Tarowy on 2023-04-02.
//
using namespace std;

#include "vector"
#include "stack"

/**
 * 144. 二叉树的前序遍历
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
 */
class LeetCode144 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack < TreeNode * > treeStack;
        TreeNode *cur = root;

        if (root == nullptr)
            return result;

        treeStack.push(cur);
        while (!treeStack.empty()) {
            cur = treeStack.top();
            treeStack.pop();
            result.push_back(cur->val);

            //先入栈右节点再入栈左节点，这样取出来的时候可以先取出左子节点
            if (cur->right != nullptr)
                treeStack.push(cur->right);
            if (cur->left != nullptr)
                treeStack.push(cur->left);
        }

        return result;
    }
};