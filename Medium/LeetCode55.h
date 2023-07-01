//
// Created by Tarowy on 2023-05-03.
//
using namespace std;

#include "vector"

/**
 * 55. 跳跃游戏
 * https://leetcode.cn/problems/jump-game/
 */
class LeetCode55 {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1)
            return true;

        int cover = 0;
        for (int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true;
        }

        return false;
    }
};
