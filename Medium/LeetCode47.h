//
// Created by Tarowy on 2023-04-27.
//
using namespace std;

#include "vector"
#include "algorithm"

/**
 * 47. 全排列 II
 * https://leetcode.cn/problems/permutations-ii/
 */
class LeetCode47 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector <vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());

        backtracking(result, path, nums, used);
        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        bool numUsed[21] = {false};
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || numUsed[nums[i] + 10])
                continue;
            used[i] = true;
            numUsed[nums[i] + 10] = true;
            path.push_back(nums[i]);
            backtracking(result, path, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};