//
// Created by Tarowy on 2023-04-20.
//
using namespace std;

#include "vector"

/**
 * 77. 组合
 * https://leetcode.cn/problems/combinations/
 */
class LeetCode77 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector <vector<int>> result;
        vector<int> temp;
        backtracking(result, temp, 1, n, k);

        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &temp, int index, int n, int k) {
        if (k == 0) {
            result.emplace_back(temp);
            return;
        }

        /**
         * n - k + 1 为剪枝操作
         * 从n开始倒着数，最后 k 个元素无需遍历
         * k表示当前集合还需要几个元素，n - k + 1 表示的是末尾 k 个元素的数量满足条件
         * 那么就无需遍历倒数第 k 个元素之后的元素，因为再往后剩余的元素数量就已经不符合条件了
         */
        for (int i = index; i <= n- k + 1; ++i) {
            temp.push_back(i);
            backtracking(result, temp, i + 1, n, k - 1);
            temp.pop_back();
        }
    }
};
