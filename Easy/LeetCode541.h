//
// Created by Tarowy on 2023-03-18.
//
using namespace std;

#include "string"
#include "algorithm"

/**
 * 541. 反转字符串 II
 * https://leetcode.cn/problems/reverse-string-ii/
 */
class LeetCode541 {
public:
    string reverseStr(string s, int k) {
        //每次跳跃2k个字符
        for (int i = 0; i < s.size(); i += (2 * k)) {
            //i到i+k的字符都在s的范围内，则反转前k个字母
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            //i到i+k的
            else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};