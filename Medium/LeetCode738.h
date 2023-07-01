//
// Created by Tarowy on 2023-07-01.
//

#ifndef LEETCODE_LEETCODE738_H
#define LEETCODE_LEETCODE738_H

#include <string>

using namespace std;

/**
 * 738. 单调递增的数字
 * https://leetcode.cn/problems/monotone-increasing-digits/
 */
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        //n = 1000
        //n = 1234
        //n = 332

        string number_string = to_string(n);
        //记录从哪位开始将数字全变成9
        int flag = number_string.size();

        //从最后一位开始往前遍历
        for (int i = number_string.size() - 1; i > 0; i--) {
            /*
             * 前一位数大于当前位数，则将前一位数减1，当前位数变为9，以确保变成这两位数之下的最大值
             * 不过这里只需要记录将数字变为9的起始位置，不需要真的变为9
             */
            if (number_string[i - 1] > number_string[i]) {
                --number_string[i - 1];
                flag = i;
            }
        }

        //从标记位开始将所有数字变为9从而得到最大值
        for (int i = flag; i < number_string.size(); ++i)
            number_string[i] = '9';

        return stoi(number_string);
    }
};

#endif //LEETCODE_LEETCODE738_H
