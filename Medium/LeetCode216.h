//
// Created by Tarowy on 2023-04-21.
//
using namespace std;

#include "vector"

/**
 * 216. 组合总和 III
 * https://leetcode.cn/problems/combination-sum-iii/
 */
class LeetCode216 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector<int>> result;
        vector<int> path;
        backtracking(result, path, 1, k, n);

        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, int startIndex, int k, int n) {
        //表示子集数量达到最大
        if (k == 0) {
            //虽然子集数量达到最大，但是子集之和的值可能未达到预期，则直接返回
            if (n == 0)
                result.push_back(path);
            return;
        }

        /*
         * k 表示当前集合还需要k个元素，那么 9 - k + 1 之后元素数量已经小于 k 了
         */
        for (int i = startIndex; i <= 9 - k + 1; ++i) {
            path.push_back(i);
            //减去当前的数后小于0，那么之后的数也不会满足条件，无需再遍历之后的数了
            if (n - i < 0)
            {
                path.pop_back();
                return;
            }
            backtracking(result, path, i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
};
