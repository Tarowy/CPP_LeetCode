//
// Created by Tarowy on 2023-05-05.
//
using namespace std;

#include "vector"

/**
 * 45. 跳跃游戏 II
 * https://leetcode.cn/problems/jump-game-ii/
 */
class LeetCode45 {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        int result = 0;
        //当前元素的最大覆盖范围
        int curDistance = 0;
        //下一步的元素最大覆盖范围
        int nextDistance = 0;

        for (int i = 0; i < nums.size(); ++i) {
            //计算最大覆盖范围
            nextDistance = max(i + nums[i], nextDistance);
            //说明在这之前的 元素覆盖范围 都没有超过 i这个下标，此时需要更新覆盖范围
            if (i == curDistance) {
                //覆盖仍未到达终点，扩大覆盖范围
                if (curDistance < nums.size() - 1) {
                    result++;
                    //更新覆盖范围
                    curDistance = nextDistance;
                    //判断是否覆盖到元素末尾
                    if (curDistance >= nums.size() - 1)
                        break;
                }else break;
            }
        }

        return result;
    }
};
