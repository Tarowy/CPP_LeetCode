//
// Created by Tarowy on 2023-04-15.
//

/**
 * 450. 删除二叉搜索树中的节点
 * https://leetcode.cn/problems/delete-node-in-a-bst/
 */
class LeetCode450 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *deleteNode(TreeNode *root, int key) {        if (root == nullptr)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        if (key > root->val)
            root->right = deleteNode(root->right, key);

        if (root->val == key){
            //值匹配，开始删除该节点
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            //左右孩子都不为空
            TreeNode *tempRight = root->right;

            /**
             * 将该节点的左子树挂到右子树的最左边
             * 因为左子树的所有节点必定小于右子树的所有元素
             * 而右子树最左边的元素就是右子树中的最小元素
             * 挂到右子树的最小元素上可以保证二叉树的性质
             */
            TreeNode *temp = tempRight;
            while (temp->left != nullptr)
                temp = temp->left;

            temp->left = root->left;
            delete root;

            return tempRight;
        }

        return root;
        if (root == nullptr)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        if (key > root->val)
            root->right = deleteNode(root->right, key);

        if (root->val == key){
            //值匹配，开始删除该节点
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            //左右孩子都不为空
            TreeNode *tempRight = root->right;

            /**
             * 将该节点的左子树挂到右子树的最左边
             * 因为左子树的所有节点必定小于右子树的所有元素
             * 而右子树最左边的元素就是右子树中的最小元素
             * 挂到右子树的最小元素上可以保证二叉树的性质
             */
            TreeNode *temp = tempRight;
            while (temp->left != nullptr)
                temp = temp->left;

            temp->left = root->left;
            delete root;

            return tempRight;
        }

        return root;
    }

};
