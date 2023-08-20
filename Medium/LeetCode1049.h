//
// Created by Tarowy on 2023-07-07.
//

#ifndef LEETCODE_LEETCODE1049_H
#define LEETCODE_LEETCODE1049_H

#include <vector>
#include <iostream>

using namespace std;


/**
 * 1049. 最后一块石头的重量 II
 * https://leetcode.cn/problems/last-stone-weight-ii/
 */
class Solution {
public:
    /**
     * stones = [2,7,4,1,8,1]
     * 将石头分成重量尽可能接近的两堆，这样相撞后得到的重量会最小
     * a b -> a-b
     * a+a b+b -> a-b + a-b -> 2a-2b
     *
     *                0  1  2  3  4  5  6  7
     *  stones[0] 2   0  0  2  2  2  2  2  2
     *  stones[1] 7   0  0  2  2  2  2  2  7
     *  stones[2] 4   0  0  2  2  4  4  6  7
     *  stones[3] 1   0  1  2  3  4  5  6  7
     *
     * @param stones
     * @return
     */
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0;
        for (const int &stone_weight: stones)
            sum += stone_weight;


        int halfSum = static_cast<int>(sum * 0.5);

        //dp[j] 表示 背包最大容量为 j 的情况下需要怎么选石头才能尽量装满背包
        vector<int> dp(halfSum + 1, 0);

        for (const int &stone_weight: stones) {
            for (int j = halfSum; j >= stone_weight; --j) {
                dp[j] = max(dp[j], dp[j - stone_weight] + stone_weight);
            }
        }

        //背包最大容量即 dp[halfSum] 有可能装不满
        return sum - (dp[halfSum] << 1);
    }
};

#endif //LEETCODE_LEETCODE1049_H
