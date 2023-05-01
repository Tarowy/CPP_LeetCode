//
// Created by Tarowy on 2023-04-27.
//
using namespace std;

#include "vector"

/**
 * 46. 全排列
 * https://leetcode.cn/problems/permutations/
 */
class LeetCode46 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector <vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtracking(result, path, nums, used);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(result, path, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};
