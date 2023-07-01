//
// Created by Tarowy on 2023-05-01.
//
using namespace std;

#include "vector"

/**
 * 376. 摆动序列
 * https://leetcode.cn/problems/wiggle-subsequence/
 */
class LeetCode376 {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        int preDiff = 0;
        int curDiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            //后一个数与当前数的差值是向上摆动还是向下摆动
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) {
                result++;
                /*
                 * 只有当前数字左右梯度不一样才会更新preDiff，
                 * 不进入该if条件，说明左右梯度一致，所以也没必要更新preDiff
                 */
                preDiff = curDiff;
            }
        }

        return result;
    }
};