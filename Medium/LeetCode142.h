//
// Created by Tarowy on 2023-03-13.
//

/**
 * 142. 环形链表 II
 * https://leetcode.cn/problems/linked-list-cycle-ii/
 */
class LeetCode142 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            //快指针一次走两格，慢指针一次走一格
            fast = fast->next->next;
            slow = slow->next;

            //快慢指针会在环里相遇
            if (fast == slow) {
                auto index1 = slow;
                auto index2 = head;

                /*
                 * 当快慢指针相遇，那么一个指针从相遇点出发，一个指针从头部出发，最后会在环的入口相遇
                 * 相遇点到入口的距离和头部到入口的距离是一致的
                 * https://www.bilibili.com/video/BV1if4y1d7ob
                 */
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }

        return nullptr;
    }
};
