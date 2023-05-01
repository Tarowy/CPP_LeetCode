//
// Created by Tarowy on 2023-04-23.
//
using namespace std;

#include "string"
#include "vector"

/**
 * 17. 电话号码的字母组合
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 */
class LeetCode17 {
    const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        vector <string> result;
        string path;
        backtracking(result, path, digits, digits.size());

        return result;
    }

    void backtracking(vector<string> &result, string &path, const string &digits, int d) {
        if (d == 0) {
            result.push_back(path);
            return;
        }

        //获取当前digits中的数字
        int index = digits[digits.size() - d] - '0';
        for (char i : letterMap[index]) {
            path.push_back(i);
            backtracking(result, path, digits, d - 1);
            path.pop_back();
        }
    }
};
