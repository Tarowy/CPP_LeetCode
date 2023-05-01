//
// Created by Tarowy on 2023-04-24.
//
using namespace std;

#include "vector"
#include "algorithm"

/**
 * 40. 组合总和 II
 * https://leetcode.cn/problems/combination-sum-ii/
 */
class LeetCode40 {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector <vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracking(result, path, candidates, target, 0);

        return result;
    }

    void
    backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &candidates, int target, int startIndex) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            /*
             * 1,1,2,5,6,7,10
             * 如果 i = 0 时找得到组合，那么下一个i = 1 时可能会找到相同的组合导致组合重复，所以不考虑 i = 1
             * 如果 i = 0 时找不到组合，那么下一个i = 1 时可能也找不到，同样不需要考虑 i = 1
             */
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            if (target - candidates[i] < 0) {
                path.pop_back();
                return;
            }
            backtracking(result, path, candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
};
