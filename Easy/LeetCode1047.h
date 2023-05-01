//
// Created by Tarowy on 2023-03-27.
//
using namespace std;
#include "string"

/**
 * 1047. 删除字符串中的所有相邻重复项
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
 */
class LeetCode1047 {
public:
    string removeDuplicates(string s) {
        string result;
        for(char ch : s){
            if (result.back() == ch) result.pop_back();
            else result.push_back(ch);
        }
        return result;
    }
};
