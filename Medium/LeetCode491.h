//
// Created by Tarowy on 2023-04-26.
//
using namespace std;

#include "vector"

/**
 * 491. 递增子序列
 * https://leetcode.cn/problems/non-decreasing-subsequences/
 */
class LeetCode491 {
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector <vector<int>> result;
        vector<int> path;
        backtracking(result, path, nums, 0, -1);

        return result;
    }

    /**
     *
     * @param nums
     * @param startIndex
     * @param lastNumIndex
     */
    void
    backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int startIndex, int lastNumIndex) {
        if (path.size() >= 2)
            result.push_back(path);

        //记录在当前层，哪个数字已经用过
        int used[201] = {0};
        for (int i = startIndex; i < nums.size(); ++i) {
            if (used[nums[i] + 100] || (lastNumIndex != -1 &&  nums[i] < nums[lastNumIndex]))
                continue;
            path.push_back(nums[i]);
            backtracking(result, path, nums, i + 1, i);
            used[nums[i] + 100] = 1;
            path.pop_back();
        }
    }
};