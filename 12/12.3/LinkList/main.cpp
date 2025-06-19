#include <iostream>
#include "ListFunc.h"
// 单链表的删除操作
// 删除单个结点,删除第i个位置的元素
/**
 * @brief 删除列表L中的第pos个结点
 * @param L 要被删除结点的列表
 * @param pos 删除的位置
 * @return 删除成功返回true,否则返回false
 */
bool DeleteListNode(LinkList &L, int pos) {
    if (L == nullptr || pos < 1) {
        return false;
    }
    LinkList p = GetElem(L, pos-1); // 删除结点的前一个结点
    if (p == nullptr) {
        return false;
    }
    LinkList q = p->next; // 拿到要删除结点的指针
    p->next = q->next;
    free(q);
    return true;
}


int main() {
    LinkList L;
    bool ret;
    L = GenerateRandomLinkList(10);
    std::cout << "Before delete:" << std::endl;
    PrintLinkList(L);
    // 删除第5个结点
    DeleteListNode(L, 5);
    std::cout << "After delete:" << std::endl;
    PrintLinkList(L);
    // 确保释放链表内存
    DeleteLinkList(L);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
