#include <iostream>
#include<stdio.h>

//线性表的链式存储
typedef int ElemType;

/**
 * 单链表的结点
 */
typedef struct LNode{ //因为结构体内使用了LNode,所以这里不能省略LNode
    ElemType data;  // 数据域
    struct LNode *next; // 指针域
}LNode, *LinkList;

// 带头节点的初始化 考研用
bool InitList(LinkList &L) {
    // L = (LNode *)malloc(sizeof(LNode)); // 创建头节点
    L = new LNode;
    L->next=nullptr;
    return true;
}
// 不带头节点的初始化 工作用
bool InitList2(LinkList &L) {
    L = nullptr;
    return true;
}

// 判断单链表是否为空
bool IsEmpty(LinkList L) {
    return L == nullptr;
}

// 单链表的插入操作
bool ListInsert(LinkList &L, int pos, ElemType e) {
    LNode *p = L; // p指向当前结点
    int j = 1;
    while (p!= nullptr && j < pos - 1) { // 找到插入位置前一个结点
        p = p->next;
        j++;
    }
    if (p == nullptr) { // 插入位置越界
        return false;
    }
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 单链表的删除操作
bool ListDelete(LinkList &L, int pos, ElemType &e) {
    LNode *p = L; // p指向当前结点
    int j = 1;
    while (p!= nullptr && j < pos - 1) { // 找到删除位置前一个结点
        p = p->next;
        j++;
    }
    if (p == nullptr || p->next == nullptr) { // 删除位置越界
        return false;
    }
    e = p->next->data;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
    return true;
}



int main() {
    LinkList L;
    InitList(L);  // 初始化带头节点的链表

    // 插入元素到头节点后
    ListInsert(L, 1, 10);
    ListInsert(L, 1, 20);

    // 插入元素到中间位置
    ListInsert(L, 2, 30);

    // 插入元素到最后一个节点之后
    ListInsert(L, 4, 40);

    // 打印链表内容
    LNode *p = L->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;

    // 测试插入位置越界
    bool result = ListInsert(L, 10, 50);
    if (!result) {
        std::cout << "Insertion failed due to out of bounds." << std::endl;
    }

    // 测试删除元素
    ElemType e;
    result = ListDelete(L, 3, e);
    if (result) {
        std::cout << "Deleted element: " << e << std::endl;
    }
    else {
        std::cout << "Deletion failed due to out of bounds." << std::endl;
    }
    // 打印链表内容
    p = L->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
    // 测试删除越界元素
    result = ListDelete(L, 10, e);
    if (!result) {
        std::cout << "Deletion failed due to out of bounds." << std::endl;
    }

    return 0;

}