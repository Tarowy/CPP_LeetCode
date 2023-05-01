struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 203. 移除链表元素
 * https://leetcode.cn/problems/remove-linked-list-elements/
 */
class LeetCode203 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        //虚拟头节点
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *current = dummyHead;

        while (current->next != nullptr) {
            //修改指向
            if (current->next->val == val) {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
                continue;
            }
            current = current->next;
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};