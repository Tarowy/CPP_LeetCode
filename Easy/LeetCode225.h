//
// Created by Tarowy on 2023-03-23.
//

using namespace std;

#include "queue"

/**
 * 225. 用队列实现栈
 * https://leetcode.cn/problems/implement-stack-using-queues/
 */
class LeetCode225 {
    class MyStack {
    private:
        queue<int> que;

    public:
        MyStack() {

        }

        void push(int x) {
            que.push(x);
        }

        int pop() {
            /*
             * 将队列的所有元素除了最后一个元素外全都移动到队尾
             * 这样第一个元素就是要出栈的元素
             */
            if (!que.empty()) {
                int size = que.size();
                size--;
                while (size--) {
                    que.push(que.front());
                    que.pop();
                }
            }

            int result = que.front();
            que.pop();
            return result;
        }

        int top() {
            return que.back();
        }

        bool empty() {
            return que.empty();
        }
    };
};
