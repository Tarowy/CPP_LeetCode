//
// Created by Tarowy on 2023-04-20.
//
using namespace std;

#include "vector"

/**
 * 108. 将有序数组转换为二叉搜索树
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
 */
class LeetCode108 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty())
            return nullptr;

        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int left, int right) {
        if (left < 0 || right >= nums.size() || left > right)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);

        int temp = right - left;
        //temp%2 是确保当 temp/2 是奇数时，mid会落在较大的那个数上
        int mid = left + temp / 2 + temp % 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }
};
