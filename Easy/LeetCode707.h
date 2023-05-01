/**
 * 707. 设计链表
 * https://leetcode.cn/problems/design-linked-list/
 */
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    MyLinkedList() {
        _size = 0;
        dummyHead = new ListNode();
    }

    int get(int index) {
        if (index < 0 || index > _size - 1)
            return -1;

        auto *current = dummyHead->next;
        //找到第index个节点
        while (index--)
            current = current->next;

        return current->val;
    }

    void addAtHead(int val) {
        auto *newHead = new ListNode(val, dummyHead->next);
        dummyHead->next = newHead;
        _size++;
    }

    void addAtTail(int val) {
        auto *newNode = new ListNode(val);
        auto *current = dummyHead;

        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;

        auto *current = dummyHead;

        //找到第index个节点的前一个节点
        while (index--)
            current = current->next;
        auto *newNode = new ListNode(val, current->next);
        current->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0)
            return;

        auto *current = dummyHead;

        //找到第index个节点的前一个节点
        while (index--)
            current = current->next;
        auto *temp = current->next;
        current->next = current->next->next;
        delete temp;
        _size--;
    }

private:
    int _size = 0;
    ListNode *dummyHead;
};
