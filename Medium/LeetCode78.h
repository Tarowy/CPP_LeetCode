//
// Created by Tarowy on 2023-04-25.
//
using namespace std;

#include "vector"
#include "algorithm"

/**
 * 78. 子集
 * https://leetcode.cn/problems/subsets/
 */
class LeetCode78 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtracking(result, path, nums, 0);

        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int startIndex) {
        result.push_back(path);

        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
