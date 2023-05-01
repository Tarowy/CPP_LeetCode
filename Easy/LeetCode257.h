//
// Created by Tarowy on 2023-04-07.
//
using namespace std;

#include "math.h"
#include "string"
#include "vector"

/**
 * 257. 二叉树的所有路径
 * https://leetcode.cn/problems/binary-tree-paths/
 */
class LeetCode257 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector <string> result;
        vector <int> path;

        traversal(root,path,result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &path, vector<string> &result) {
        path.push_back(root->val);

        //到达了最底部的节点，将路径加入到结果集中
        if (root->left == nullptr && root->right == nullptr) {
            string resultPath;

            for (int i = 0; i < path.size() - 1; ++i) {
                resultPath += (to_string(path[i]) + "->");
            }
            resultPath += to_string(path[path.size() - 1]);
            result.push_back(resultPath);
            return;
        }

        if (root->left != nullptr){
            traversal(root->left, path, result);
            path.pop_back();
        }


        if (root->right != nullptr){
            traversal(root->right, path, result);
            path.pop_back();
        }
    }
};
