//
// Created by Tarowy on 2023-07-05.
//

#include <vector>

using namespace std;

#ifndef LEETCODE_KNAPSACKPROBLEM_H
#define LEETCODE_KNAPSACKPROBLEM_H

class Knapsack {
public:
    int solution() {
        vector<vector<int>> dp;
        //物品重量
        int item_weight[3] = {1, 4, 3};
        //物品价值
        int item_value[3] = {15, 30, 20};

        int i = 0, j = 0;
        /*
         * i 表示第几个物品，j 表示物品 i 的重量
         * dp[i][j] => 表示背包最大重量为 j 情况下，从 0~i 的物品任意选择拿或者不拿所得到的最大价值
         * dp[i - 1][j] => 表示最大重量为j，不拿物品i的情况下所能得到的最大价值，此时最大价值只与前 0~i-1 个物品相关
         *
         * dp[i - 1][j - item_weight[i]] + item_value[i] => 表示要拿物品i，此时最大价值不仅与前 0~i 个物品相关，还与物品i相关
         * dp[i - 1][j - item_weight[i]] => 是为物品i腾出空间。在除去物品i的重量所剩下的最大重量的情况下所能得到的最大价值，与前 0~i-1 个物品相关
         *
         * 二维dp可以颠倒遍历顺序，而且是顺序遍历
         */
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item_weight[i]] + item_value[i]);

        /*
         * 由于遍历每一行的数据只与上一行有关，所以可以降低为1维数组
         * dp[j] 表示最大重量为j 的情况下，从 0~i 的物品任意选择拿或者不拿所得到的最大价值
         * max(dp[j], dp[j - item_weight[i]] + item_value[i]) 中的 dp[j] 表示不拿物品i
         * dp[j - item_weight[i]] 表示拿当前物品
         *
         * 一维dp不能颠倒顺序。而且必须倒序遍历，正序会导致数组前面的值被覆盖，后面再请求前面的值的时候含义被改变
         */
        dp[j] = max(dp[j], dp[j - item_weight[i]] + item_value[i]);

        /*
         * 完全背包就是在01背包的基础上，一个物品可以装无数次，这样就不用倒序遍历了，直接正序遍历就会成为完全背包，
         * 完全背包的遍历顺序可以颠倒，既可以先遍历背包也可以先遍历物品
         */
        dp[j] = max(dp[j], dp[j - item_weight[i]] + item_value[i]);
    }
};

#endif //LEETCODE_KNAPSACKPROBLEM_H
