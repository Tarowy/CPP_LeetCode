//
// Created by Tarowy on 2023-03-27.
//
using namespace std;

#include "string"
#include "stack"

/**
 * 20. 有效的括号
 * https://leetcode.cn/problems/valid-parentheses/
 */
class LeetCode20 {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> bracketsStack;

        //字符长度为奇数一定不满足条件
        if (size % 2 != 0)
            return false;

        for (int i = 0; i < size; i++) {
            //每遇到左括号就将相应的右括号加入到栈中
            if (s[i] == '(') bracketsStack.push(')');
            else if (s[i] == '{') bracketsStack.push('}');
            else if (s[i] == '[') bracketsStack.push(']');
            //遇到右括号时，如果栈已经空了，或者括号不匹配则不满足条件
            else if (bracketsStack.empty() || bracketsStack.top() != s[i]) return false;
            else bracketsStack.pop();
        }

        //所有字符遍历完成后，如果栈不为空，则匹配失败
        return bracketsStack.empty();
    }
};