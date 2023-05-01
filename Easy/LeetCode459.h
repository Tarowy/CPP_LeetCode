//
// Created by Tarowy on 2023-03-23.
//
using namespace std;

#include "string"

/**
 * 459. 重复的子字符串
 * https://leetcode.cn/problems/repeated-substring-pattern/
 */
class LeetCode459 {
public:
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        //当一个字符串由重复子串组成的，最长相等前后缀不包含的子串就是最小重复子串
        getNext(next, s);

        int len = s.size();
        /*
         * 可以根据next前缀表来寻找最小重复子串
         * https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html
         */
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
            return true;
        return false;
    }

    void getNext(int next[], const string &s) {
        int i = 1, j = 0;
        next[0] = 0;

        while (i < s.size()) {
            if (s[i] == s[j])
                next[i++] = ++j;
            else if (j == 0) //回退到0位置依然与i位置的字符不匹配
                next[i++] = 0;
            else //不匹配则回退，寻找与i位置匹配的字符
                j = next[j - 1];
        }
    }
};