//
// Created by Tarowy on 2023-03-28.
//
using namespace std;

#include "string"
#include "vector"
#include "stack"

/**
 * 150. 逆波兰表达式求值
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 */
class LeetCode150 {
public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> numberStack;

        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                long long num1 = numberStack.top();
                numberStack.pop();
                long long num2 = numberStack.top();
                numberStack.pop();

                if (tokens[i] == "+") numberStack.push(num2 + num1);
                if (tokens[i] == "-") numberStack.push(num2 - num1);
                if (tokens[i] == "*") numberStack.push(num2 * num1);
                if (tokens[i] == "/") numberStack.push(num2 / num1);
                continue;
            }
            numberStack.push(stoll(tokens[i]));
        }

        return numberStack.top();
    }
};
