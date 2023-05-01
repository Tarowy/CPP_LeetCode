//
// Created by Tarowy on 2023-04-09.
//
using namespace std;

#include "iostream"
#include "vector"
#include "unordered_map"

/**
 * 106. 从中序与后序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
class LeetCode106 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    //储存每个元素在中序遍历中的下标
    unordered_map<int, int> elementIndex;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //记录每个元素在中序遍历下的索引
        for (int i = 0; i < inorder.size(); ++i)
            elementIndex.insert(pair<int, int>(inorder[i], i));

        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    /**
     *
     * @param inorder 中序遍历结果
     * @param postorder 后序遍历结果
     * @param il 中序遍历结果的左指针
     * @param ir 中序遍历结果的右指针
     * @param pl 后序遍历结果的左指针
     * @param pr 后序遍历结果的右指针
     * @return
     */
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr) {
        if (il > ir || pl > pr)
            return nullptr;

        if (il == ir)
            return new TreeNode(inorder[il]);

        //后序遍历 子序列 的最后一个元素就是根节点
        int midNode = postorder[pr];
        //获取根节点在中序遍历中的下标位置，从而将中序遍历切割成 左-中(根节点)-右 的序列
        int midIndex = elementIndex[midNode];

        TreeNode *root = new TreeNode(midNode);

        //il到midIndex的数量 就是 左子树节点的数量，所以从 后序序列中 挑选出 对应的数量的子序列，那么 后序序列中剩下的 就是 右子树节点的数量
        root->left = build(inorder, postorder, il, midIndex - 1, pl, pl + (midIndex - il) - 1);
        root->right = build(inorder, postorder, midIndex + 1, ir, pl + (midIndex - il), pr - 1);

        return root;
    }
};
