#include <iostream>
// 2019年41题

typedef struct node {
    int data;
    node *next;
} NODE;

/**
 * @brief 打印链表
 * @param head 链表头指针
 * @return
 */
void printList(node *head) {
    node *curr = head->next;
    while (curr!= nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

/**
 * @brief 找链表的中间节点
 * @param head 链表头指针
 * @return
 */
node * findMid(node *head) {
    node *slow = head;
    node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // 奇数返回(n+1)/2
}

void find_middle(node* L, node*& L2) {
    L2 = (node*)malloc(sizeof(node));
    node* slow;
    node* fast;
    slow = L->next;
    fast = L->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (nullptr == fast) {
            break;
        }
        fast = fast->next;
        if (nullptr == fast) {
            break;
        }
        slow = slow->next;
    }
    L2->next = slow->next;
    slow->next = nullptr;
}

/**
 * @brief 带头结点的链表逆置
 * @param head 链表头指针
 * @return
 */
node * reverseList(node *head) {
    node *prev = nullptr;
    node *curr = head->next;
    node *next = nullptr;
    while (curr!= nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
    return head;
}

/**
 * @brief 合并两个链表,轮流插入到dummy节点的后面
 * @param head1 链表1头指针
 * @param head2 链表2头指针
 * @return
 */
node * mergeList(node *head1, node *head2) {
    node *dummy = (node*)malloc(sizeof(node));
    dummy->next = nullptr;
    node *tail = dummy;
    head1 = head1->next;
    head2 = head2->next;
    while (head1 != nullptr && head2 != nullptr) {
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;

        tail->next = head2;
        tail = tail->next;

        head2 = head2->next;
    }
    // 因为head1要么节点数与head2相同,要么多一个节点,所以最后要判断一下
    if (head1 != nullptr) {
        tail->next = head1;
    }
    return dummy;

}

node * SortList(node *head) {
    node *L2 = nullptr;
    find_middle(head, L2);
    L2 = reverseList(L2);
    return mergeList(head, L2);
}

int main() {
    // 创建一个带头结点的链表
    node *head = (node*)malloc(sizeof(node));
    head->next = nullptr;
    // 构造链表
    node *p = head;
    for (int i = 1; i <= 6; i++) {
        node *q = (node*)malloc(sizeof(node));
        q->data = i;
        q->next = nullptr;
        p->next = q;
        p = q;
    }
    printList(head);
    head = SortList(head);
    printList(head);

    return 0;
}