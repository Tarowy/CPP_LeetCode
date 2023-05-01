//
// Created by Tarowy on 2023-04-25.
//
using namespace std;
#include "vector"
#include "algorithm"

/**
 * 90. 子集 II
 * https://leetcode.cn/problems/subsets-ii/
 */
class LeetCode90 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtracking(result, path, nums, 0);

        return result;
    }

    void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int startIndex) {
        result.push_back(path);

        for (int i = startIndex; i < nums.size(); ++i) {
            //上一个数和当前数相同，那么上一个循环时已经将包含当前数的集合加入过结果集，会导致重复
            if (i > startIndex && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            backtracking(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
