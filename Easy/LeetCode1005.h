//
// Created by Tarowy on 2023-05-15.
//
#include "vector"
#include "algorithm"

using std::vector;
using std::sort;

/**
 * 1005. K 次取反后最大化的数组和
 * https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 */
class LeetCode1005 {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int result = 0;
        //按绝对值大小排序
        sort(nums.begin(), nums.end(), cmp);

        for (int &num: nums) {
            //将负数转变为正数
            if (k > 0 && num < 0) {
                --k;
                num *= -1;
            }
        }

        /*
         * 如果k没用完，则对绝对值最小的数反复取反，消耗k的次数，
         * 这样即使最后取反的结果是负数，对结果的影响也最小
         */
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        for (int &num: nums)
            result += num;

        return result;
    }
};
