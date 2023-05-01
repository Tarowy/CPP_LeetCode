//
// Created by Tarowy on 2023-04-24.
//
using namespace std;

#include "vector"
#include "string"

/**
 * 131. 分割回文串
 * https://leetcode.cn/problems/palindrome-partitioning/
 */
class LeetCode131 {
public:
    vector<vector<string>> partition(string s) {
        vector <vector<string>> result;
        vector <string> path;
        backtracking(result, path, s, 0);

        return result;
    }

    void backtracking(vector<vector<string>> &result, vector<string> &path, const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); ++i) {
            //从startIndex到i的子串不是回文字串，那么直接不考虑这次回溯
            if (!isPalindrome(s, startIndex, i))
                continue;
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
            backtracking(result, path, s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};