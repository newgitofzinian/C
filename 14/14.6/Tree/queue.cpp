//
// Created by 子年 on 25-6-23.
//
// 初始化队列
#include "function.h"
void InitQueue(LinkQueue& Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}
bool QueueEmpty(LinkQueue Q) {
    return Q.head == nullptr;
}
// 入队
void EnQueue(LinkQueue &Q, ElemType x) {
    try {
        LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = x;
        p->next = nullptr;
        if (QueueEmpty(Q)) { // 队列为空,需要首尾指针都指向新节点
            Q.head = p;
            Q.tail = p;
        }else{
            Q.tail->next = p;
            Q.tail = p;
        }
    } catch (std::bad_alloc e) {
        std::cerr << "Out of memory!" << std::endl;
    }
}
// 出队
ElemType DeQueue(LinkQueue &Q){
    if (QueueEmpty(Q)) {
        std::cerr << "Queue is empty!" << std::endl;
        return nullptr;
    }
    ElemType x = Q.head->data;
    LinkNode *p = Q.head;
    Q.head = Q.head->next;
    if (Q.head == nullptr) { // 队列中只有一个节点,删除后无结点
        Q.tail = nullptr;
    }
    free(p);
    return x;
}

// 打印队列
void PrintQueue(LinkQueue Q) {
    if (QueueEmpty(Q)) {
        std::cout << "Queue is empty!" << std::endl;
    }
    LinkNode *p = Q.head;
    while (p!= nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}