//
// Created by Tarowy on 2023-07-01.
//

#ifndef LEETCODE_LEETCODE509_H
#define LEETCODE_LEETCODE509_H

/**
 * 509. 斐波那契数
 * https://leetcode.cn/problems/fibonacci-number/
 */
class Solution {
public:
    int fib(int n) {
        //dp数组储存斐波那契数，由于状态方程只与前两个数相关，所以只需要三个数组大小
        int dp[3]{0, 1, 1};

        //利用状态方程计算
        for (int i = 2; i <= n; ++i)
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];

        //获取需要的斐波那契数值
        return dp[n % 3];
    }
};

#endif //LEETCODE_LEETCODE509_H
