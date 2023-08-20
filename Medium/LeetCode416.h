//
// Created by Tarowy on 2023-07-06.
//

#ifndef LEETCODE_LEETCODE416_H
#define LEETCODE_LEETCODE416_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * 416. 分割等和子集
 * https://leetcode.cn/problems/partition-equal-subset-sum/
 */
class Solution {
public:
    /**
     * [1,5,11,5]  分割成 [1, 5, 5] 和 [11]
     * [1,2,3,5]  不能分割
     *
     * 如果总和是奇数，那么该数组一定不能分割
     * @param nums
     * @return
     */
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 2 != 0)
            return false;

        //            0  1  2  3  4  5  6  7  8  9  10 11
        //nums[0]  1  0  1  1  1  1  1  1  1  1  1  1  1
        //nums[1]  5  0  1  1  1  1  5  6  6  6  6  6  6
        //nums[2] 11  0  1  1  1  1  5  6  6  6  6  6  11
        //nums[3]  5  0  1  1  1  1  5  6  6  6  6  6  11
        int halfSum = static_cast<int>(sum * 0.5);
        vector<int> dp(halfSum + 1, 0); //dp代表最大容量为i时，选取的数字最大能组成的总和的大小

        for (int i = 0; i < nums.size() - 1; ++i) {
            //逆序遍历防止数据覆盖，如果背包容量小于nums，肯定装不下，不需要再向下遍历
            for (int j = dp.size() - 1; j >= nums[i]; --j) {
                //dp[j]会尽量装满最大容量。这里需要max，如果最大容量是4，且数字是2、2、3的话，遍历到3的时候肯定是不选3得到的结果大
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[halfSum] == halfSum;
    }
};

#endif //LEETCODE_LEETCODE416_H
