
/**
 * 24. 两两交换链表中的节点
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
 */
class LeetCode24 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *swapPairs(ListNode *head) {
        auto dummyHead = new ListNode(0, head);
        auto current = dummyHead;

        /*
         * current->next != nullptr 确保current停在链表末尾
         * current->next->next != nullptr 确保链表的个数是偶数，如果奇数就不管最后一个节点了
         */
        while (current->next != nullptr && current->next->next != nullptr) {
            auto temp = current->next->next;
            auto temp1 = temp->next;

            current->next->next = temp1;
            temp->next = current->next;
            current->next = temp;

            current = current->next->next;
        }

        return dummyHead->next;
    }
};


