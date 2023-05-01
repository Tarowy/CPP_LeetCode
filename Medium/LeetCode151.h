//
// Created by Tarowy on 2023-03-19.
//
using namespace std;

#include "string"

/**
 * 151. 反转字符串中的单词
 * https://leetcode.cn/problems/reverse-words-in-a-string/
 */
class LeetCode151 {
    string reverseWords(string s) {
        removeExtraSpace(s);

        //将整个字符串反转
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0

        //再将每个单词反转，即可得到反转单词的字符串
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }

    void removeExtraSpace(string &s){
        int fast = 0;
        int slow = 0;

        //先移除多余的空格
        for (; fast < s.size(); ++fast) {

            if (s[fast] != ' ') {
                if (slow != 0)
                    s[slow++] = ' ';

                //将当前单词全都移动到slow指向的地方
                while (fast < s.size() && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
    }

    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

};
