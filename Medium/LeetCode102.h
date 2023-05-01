//
// Created by Tarowy on 2023-04-05.
//
using namespace std;

#include "vector"
#include "queue"


/**
 * 102. 二叉树的层序遍历
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/
 */
class LeetCode102 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> result;
        queue < TreeNode * > treeQueue;
        treeQueue.push(root);

        if (root == nullptr)
            return result;

        while (!treeQueue.empty()) {
            vector<int> tmp;
            int size = treeQueue.size();

            while (size--) {
                TreeNode *treeNode = treeQueue.front();
                tmp.push_back(treeNode->val);
                treeQueue.pop();

                if (treeNode->left != nullptr)
                    treeQueue.push(treeNode->left);
                if (treeNode->right != nullptr)
                    treeQueue.push(treeNode->right);
            }
            result.push_back(tmp);
        }

        return result;
    }
};
