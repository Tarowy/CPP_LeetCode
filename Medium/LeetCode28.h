//
// Created by Tarowy on 2023-03-21.
//
using namespace std;

#include "string"
#include "iostream"

/**
 * 28. 找出字符串中第一个匹配项的下标
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 */
class LeetCode28 {
public:
    int strStr(string haystack, string needle) {
        int next[needle.size()];

        getNext(next, needle);

        int i = 0, j = 0;
        for (; i < haystack.size(); ++i) {

            //不相等，则根据前缀表回退j索引，如果不相等则需要一直回退
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];

            //相等则继续比较
            if (haystack[i] == needle[j])
                j++;

            //前缀表匹配完说明找到了需要的索引位置
            if (j == needle.size())
                return i - needle.size() + 1;
        }

        return -1;
    }

    /**
     * 求Next前缀表
     * @param next
     * @param s
     */
    void getNext(int *next, const string &s) {
        int i = 1, j = 0;
        next[0] = 0;

        // a a b a a b a a f
        //[ a a b a a f ]为例
        //[ 0 1 0 1 2 0 ]
        while (i < s.size()) {
            if (s[j] == s[i]) {
                /*
                 * j能前进就说明从 0 到 j 的字符 和 i 的前 j+1 个字符是相等的
                 * 这是因为前一轮结果会影响这一轮结果。
                 * 如果前一轮结果相等，这一轮也相等，那么j就会加一，就这样一轮轮下去
                 */
                next[i++] = ++j;

            } else if (j == 0) {
                //s[j]与s[i]不相等，同时j也已经回退到了0索引，则直接给当前i赋值0
                next[i++] = 0;

            } else {
                /*
                 * 为什么回退不用j--：
                 * j代表的是 [从 0 到 j 的字符] 和 [i 的前 j 个字符包含 i 本身] 是相等的
                 * 如果直接使用j--，[从 0 到 j 的字符] 和 [i 的前 j 个字符包含 i 本身] 不一定相等
                 * https://www.bilibili.com/video/BV16X4y137qw
                 *
                 * 当i在当前j位置时，[从 0 到 j 的字符] 就是 当前 [i 的前 j 个字符]
                 */
                j = next[j - 1]; //防止j越界
            }
        }
    }
};

int main() {
    LeetCode28 kmp;

    string s = "abbabbbabaa";
    int next[s.size()];

    kmp.getNext(next, s);

    for (int i = 0; i < s.size(); ++i) {
        cout << next[i] << " ";
    }
    return 0;
}
