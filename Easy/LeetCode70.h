//
// Created by Tarowy on 2023-07-02.
//

#ifndef LEETCODE_LEETCODE70_H
#define LEETCODE_LEETCODE70_H

#include <vector>
#include <climits>

using namespace std;

/**
 * 70. 爬楼梯
 * https://leetcode.cn/problems/climbing-stairs/
 */
class Solution {
public:
    /**
     * 使用完全背包求解
     * 比如第三个台阶，可以先一步再两步，也可以先两步再一步，所以是个组合问题
     * 先遍历背包再遍历物品
     *
     *    0  1  2  3  4
     * 1  1  1  1  2  3
     * 2  X  X  2  3  5
     */
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 1; j <= 2; ++j) {
                dp[i] = dp[i] + dp[i - j];
            }
        }

        return dp[n];
    }

    /**
     * 由于只能迈一步或者两步，所以到达n台阶的方法只与 n-1 和 n-2 的台阶有关
     * 到达 n-1 阶之后只需要1步，到达 n-2 阶之后需要2步
     * 所以 总方法数 是 （到达 n-1 的方法数） + （到达 n-2 的方法数）
     * 注意求的不是步数，而是方法数，不管哪种方法到达 n-1 阶后，都只需要 1 步
     * 所以方法数还是 n-1 的方法数
     */
    int climbStairs1(int n) {
        //本题状态方程相当于斐波那契数列
        int dp[3]{0, 1, 1};

        //利用状态方程计算
        for (int i = 2; i <= n; ++i)
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];

        //获取需要的斐波那契数值
        return dp[n % 3];
    }
};

#endif //LEETCODE_LEETCODE70_H
