#include <iostream>
#include "ListFunc.h"
// 往第i个位置插入一个节点
// 时间复杂度O(i)
// 空间复杂度O(1)

bool ListFrontInsert(LinkList L, int InsertPos, ElemType InsertVal) {
    LinkList p = GetElem(L, InsertPos-1);
    if (p == NULL) {
        return false;
    }
    try {
        LinkList q;
        q=(LinkList)malloc(sizeof(LNode));
        q->data=InsertVal;
        q->next=p->next;
        p->next=q;
        return true;
    } catch (std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return false;
    }
}

int main() {
    // size_t x;
    LinkList L;
    L = GenerateRandomLinkList(10);
    bool ret;
    std::cout << "Before insertion: " << std::endl;
    LinkListPrint(L);
    std::cout << "Insert at position 3: " << std::endl;
    if (ListFrontInsert(L, 12, 100)) {
        std::cout << "Insertion succeeded." << std::endl;
    }
    else {
        std::cout << "Insertion failed." << std::endl;
    }
    std::cout << "After insertion: " << std::endl;
    LinkListPrint(L);

    // 确保释放链表内存
    DeleteLinkList(L);
    return 0;
}