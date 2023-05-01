//
// Created by Tarowy on 2023-04-23.
//
using namespace std;

#include "vector"
#include "algorithm"

/**
 * 39. 组合总和
 * https://leetcode.cn/problems/combination-sum/
 */
class LeetCode39 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector <vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtracking(result, path, candidates, target, 0);

        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &candidates, int target, int startIndex) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            //减去当前的值已经小于0了，那么该元素之后的元素也不满足条件，所以直接结束当前递归
            if (target - candidates[i] < 0){
                path.pop_back();
                return;
            }
            /*
             * 直接将当前的索引向下传递，这样下一层递归会直接从当前索引开始，
             * 从而避免了比i小的值又被遍历导致的集合重复
             */
            backtracking(result, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
