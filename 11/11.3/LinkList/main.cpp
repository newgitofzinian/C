#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// 头插法新建链表
// 开始 -->   定义链表头指针 --> 头节点申请空间
// -->  scanf读取第一个元素值   -->     开启while循环建链表
// -->  打印链表    --> 结束

#define MAXSIZE 50 // 定义最大链表长度
typedef int ElemType;
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 释放链表空间
void FreeList(LinkList L) {
    LNode *p = L->next, *q; // 指向链表的第一个结点
    while (p) { // 循环释放结点空间
        q = p->next;
        delete p;
        p = q;
    }
    delete L; // 释放头结点空间
}

// 从建立一个空表,生成新结点,并将读取到的数据存放到新结点的数据域
// 如何将新结点插入到当前链表的表头
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    ElemType x;
    // L = new LNode; // 创建头节点
    L = (LinkList)malloc(sizeof(LNode)); // 创建头节点 C方法
    L->next = nullptr; // 头节点的next指针指向空
    scanf("%d", &x);
    // std::cout << "请输入第一个元素: ";
    // std::cin >> x;
    while (x!= -1) {
        s = (LinkList)malloc(sizeof(LNode)); // 申请新结点 C方法
        // s = new LNode; // 申请新结点
        s->data = x; // 存放数据
        s->next = L->next; // 新结点的next指针指向原®链表的第一个结点
        L->next = s; // 原链表的第一个结点指向新结点
        // std::cout << "请输入下一个元素(-1结束): ";
        // std::cin >> x;
        scanf("%d", &x);
    }
    // FreeList(s); // 释放链表空间
    return L; // 返回链表头指针
}

// 打印链表
void PrintList(LinkList L) {
    LNode *p = L->next; // 指向链表的第一个结点
    while (p) { // 循环打印链表
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}



int main() {
    LinkList List1 = nullptr; // 定义链表头指针
    List_HeadInsert(List1); // 调用函数生成链表
    PrintList(List1); // 打印链表
    FreeList(List1); // 释放链表空间
    return 0;
}