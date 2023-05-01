//
// Created by Tarowy on 2023-04-10.
//
using namespace std;

#include "vector"
#include "unordered_map"

/**
 * 105. 从前序与中序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
class Leetcode105 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    unordered_map<int, int> elementIndex;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            elementIndex[inorder[i]] = i;

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    /**
     *
     * @param preorder 先序遍历结果
     * @param inorder 中序遍历结果
     * @param pl 先序遍历结果的左指针
     * @param pr 先序遍历结果的右指针
     * @param il 中序遍历结果的左指针
     * @param ir 中序遍历结果的右指针
     */
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir)
            return nullptr;
        if (ir == il)
            return new TreeNode(inorder[il]);

        //先序序列的第一个元素就是根节点
        int midNode = preorder[pl];
        //根节点所在的中序序列的索引
        int midIndex = elementIndex[midNode];

        TreeNode *root = new TreeNode(midNode);

        //从 il到midIndex 的距离，即 根节点 的 左子树的数量，那么剩下的就是右子树
        int count = midIndex - il;
        root->left = build(preorder, inorder, pl + 1, pl + count, il, midIndex - 1);
        root->right = build(preorder, inorder, pl + count + 1, pr, midIndex + 1, ir);

        return root;
    }
};
