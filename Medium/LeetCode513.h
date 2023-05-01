//
// Created by Tarowy on 2023-04-09.
//
using namespace std;

#include "queue"

/**
 * 513. 找树左下角的值
 * https://leetcode.cn/problems/find-bottom-left-tree-value/
 */
class LeetCode513 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int findBottomLeftValue(TreeNode *root) {
        queue < TreeNode * > treeQueue;

        treeQueue.push(root);
        while (!treeQueue.empty()) {
            root = treeQueue.front();
            treeQueue.pop();

            //先入队右边的，这样层序遍历的顺序是从右到左，这样最后一个元素就是最左边的元素
            if (root->right != nullptr)
                treeQueue.push(root->right);
            if (root->left != nullptr) {
                treeQueue.push(root->left);
            }
        }

        return root->val;
    }
};
