//
// Created by Tarowy on 2023-04-11.
//
using namespace std;

#include "vector"

/**
 * 654. 最大二叉树
 * https://leetcode.cn/problems/maximum-binary-tree/
 */
class LeetCode654 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int l, int r) {
        if (l > r)
            return nullptr;

        if (l == r)
            return new TreeNode(nums[l]);

        int maxIndex = l;
        //寻找区间最大值的下标
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = build(nums, l, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, r);

        return root;
    }
};
