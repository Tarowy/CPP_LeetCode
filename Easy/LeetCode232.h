//
// Created by Tarowy on 2023-03-23.
//
using namespace std;

#include "stack"

/**
 * 232. 用栈实现队列
 * https://leetcode.cn/problems/implement-queue-using-stacks/
 */
class LeetCode232 {
    class MyQueue {
    private:
        stack<int> stackIn;
        stack<int> stackOut;

    public:

        MyQueue() {

        }

        void push(int x) {
            stackIn.push(x);
        }

        int pop() {
            /*
             * 如果输出栈为空，则将输入栈的所有元素pop到输出栈中，这样才能保证顺序不乱
             * 不能一pop就将所有元素移过去
             */
            if (stackOut.empty()) {
                while (!stackIn.empty()) {
                    stackOut.push(stackIn.top());
                    stackIn.pop();
                }
            }

            int result = stackOut.top();
            stackOut.pop();
            return result;
        }

        int peek() {
            int result = pop();
            stackOut.push(result);
            return result;
        }

        bool empty() {
            return stackIn.empty() && stackOut.empty();
        }
    };

};
