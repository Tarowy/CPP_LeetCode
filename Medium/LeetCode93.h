//
// Created by Tarowy on 2023-04-25.
//
using namespace std;

#include "vector"
#include "string"

/**
 * 93. 复原 IP 地址
 * https://leetcode.cn/problems/restore-ip-addresses/
 */
class LeetCode93 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector <string> result;
        backtracking(result, s, 0, 0);

        return result;
    }

    /**
     *
     * @param startIndex 遍历开始的索引
     * @param pointNum 加入的分割点的数量
     */
    void backtracking(vector<string> &result, string &s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            //判断最后一个分割点之后的字串是否符合要求
            if (!isValid(s,startIndex,s.size()-1))
                return;
            result.push_back(s);
            return;
        }

        for (int i = startIndex; i < startIndex + 3; ++i) {
            if (!isValid(s, startIndex, i))
                continue;
            //在不同分割位置插入分割点
            s.insert(s.begin() + i + 1, '.');
            pointNum++;
            //加入分割点后,startIndex是当前字符的后两个字符
            backtracking(result, s, i + 2, pointNum);
            pointNum--;
            s.erase(s.begin() + i + 1);
        }
    }

    /**
     * 判断分割的ip子串是否合法
     * @param s
     * @param start
     * @param end
     * @return
     */
    bool isValid(const string &s, int start, int end) {
        if (start > end) {
            return false;
        }

        //只有0单独存在的时候才合法，此时s[start]等于s[end]
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
};

