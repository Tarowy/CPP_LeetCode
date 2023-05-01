/**
 * 206. 反转链表
 * https://leetcode.cn/problems/reverse-linked-list/
 */
class LeetCode206 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        //每次传回链表末尾节点的指针
        auto lastNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return lastNode;
    }
};