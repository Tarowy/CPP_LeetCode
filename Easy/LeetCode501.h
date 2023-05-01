//
// Created by Tarowy on 2023-04-13.
//
using namespace std;

#include "vector"

/**
 * 501. 二叉搜索树中的众数
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/
 */
class LeetCode501 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    //记录重复次数最多次的数字的出现次数
    int maxCount;
    //统计当前重复数字的重复次数
    int count;
    //当前被记录出现次数的数字
    int modeValue;
    TreeNode *pre;
    vector<int> result;

    void traversal(TreeNode *root) {
        if (root == nullptr)
            return;

        traversal(root->left);

        if (pre != nullptr) {
            //该数与前一个数相等，则增加计数器
            if (root->val == pre->val) {
                count++;
            } else {
                modeValue = root->val;
                count = 1;
            }
        } else {
            modeValue = root->val;
            count = 1;
        }

        pre = root;

        if (count > 0) {
            //该数字的出现次数大于之前出现次数最多的数字
            if (count > maxCount) {
                maxCount = count;
                result.clear();
                result.push_back(modeValue);
            } else if (count == maxCount) {
                result.push_back(modeValue);
            }
        }

        traversal(root->right);
    }

    /**
     * 二叉搜索树的遍历结果是有序的，相同的数会被放在一起，只需要记录相同的数即可
     * @param root
     * @return
     */
    vector<int> findMode(TreeNode *root) {
        maxCount = modeValue = count = 0;
        pre = nullptr;
        result.clear();

        traversal(root);
        return result;
    }
};

