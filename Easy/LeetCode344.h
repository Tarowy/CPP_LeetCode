//
// Created by Tarowy on 2023-03-18.
//
#include "vector"

using namespace std;

/**
 * 344. 反转字符串
 * https://leetcode.cn/problems/reverse-string/
 */
class LeetCode344 {
public:
    void reverseString(vector<char> &s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j)
            swap(s[i],s[j]);
    }
};
