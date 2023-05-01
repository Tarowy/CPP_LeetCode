

/**
 * 19. 删除链表的倒数第 N 个结点
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 */
class LeetCode19 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummyHead = new ListNode(0, head);
        /*
         * 快指针先移动N+1步，此时慢指针还在原点，则快慢指针的距离相差N+1
         * 当快指针指向NULL时，慢指针指向的就是倒数第N+1个节点
         */
        auto fast = dummyHead;
        auto slow = dummyHead;

        //使快指针走N+1步
        n++;
        while (n-- && fast != nullptr)
            fast = fast->next;

        //同时移动快慢指针
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        auto temp = slow->next;
        slow->next = temp->next;
        delete temp;

        temp = dummyHead->next;
        delete dummyHead;

        return temp;
    }
};
