//
// Created by 子年 on 25-6-19.
//

#include "ListFunc.h"

// 带头节点的初始化 考研用
bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode)); // 创建头节点
    // L = new LNode;
    L->next=nullptr;
    return true;
}
// 判断单链表是否为空
bool IsEmpty(LinkList L) {
    return L == nullptr;
}
LinkList LinkTailInsert(LinkList &L, int n) {
    // ElemType x;
    // L = (LinkList)malloc(sizeof(LNode)); // 头结点
    LNode *s, *r = L; // r为表尾指针
    // scanf("%d", &x);
    // while (x!=-1) {
    //     s = (LinkList)malloc(sizeof(LNode));
    //     s->data = x;
    //     r->next = s;
    //     r = s;  // r指向新的尾结点
    //     scanf("%d", &x);
    // }
    for (int i = 0; i < n; ++i) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = std::rand() % 100; // 生成0到99之间的随机数
        r->next = s;
        r = s;  // r指向新的尾结点
    }
    r->next = nullptr;
    return L;
}
void PrintLinkList(LinkList L) {
    LNode *p = L->next;
    while (p!= nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
// 自动生成链表返回并打印
LinkList GenerateRandomLinkList(int n) {
    LinkList L;
    InitList(L);
    std::srand(std::time(0)); // 使用当前时间作为随机数种子
    L = LinkTailInsert(L, n);
    PrintLinkList(L);
    return L;
}
// 按值查找,并返回元素所在位置的指针,以及元素下标
std::pair<LinkList, int> LocateElem(LinkList L, ElemType x) {
    LNode *p = L->next;  // 没有可能会因为头结点的存在而导致错误
    int i = 0;
    while (p!= nullptr) {
        if (p->data == x) {
            return std::make_pair(p, i);
        }
        p = p->next;
        i++;
    }
    return std::make_pair(nullptr, -1);
}
// 按位置序号(1开始)查找
LinkList GetElem(LinkList L, size_t SearchPos) {

        LNode *p = L;
        size_t i = 0;
        while (p!= nullptr && i < SearchPos) {
            p = p->next;
            i++;
        }
        return p;

}
// 删掉链表
void DeleteLinkList(LinkList &L) {
    LNode *p = L->next, *q;
    while (p!= nullptr) {
        q = p;
        p = p->next;
        free(q);
    }
    free(L);
}
LinkList LinkHeadInsert(LinkList &L) {
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头节点 C方法
    L->next = nullptr; // 头节点的next指针指向空
    scanf("%d", &x);
    while (x!= -1) {
        s = (LinkList)malloc(sizeof(LNode)); // 申请新结点 C方法
        s->data = x; // 存放数据
        s->next = L->next; // 新结点的next指针指向原®链表的第一个结点
        L->next = s; // 原链表的第一个结点指向新结点
        scanf("%d", &x);
    }
    return L; // 返回链表头指针
}

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
