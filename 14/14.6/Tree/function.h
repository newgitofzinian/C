//
// Created by 子年 on 25-6-23.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

typedef char BiElemType;
typedef struct BiTNode {
    BiElemType data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// Queue data structure
// typedef int ElemType;
typedef BiTree ElemType;
typedef struct LinkNode {
    ElemType data;
    LinkNode* next;
}LinkNode;
typedef struct {
    LinkNode* head;
    LinkNode* tail;
}LinkQueue;
// tag 结构体是辅助队列使用
typedef struct tag {
    BiTree addr;   // 存的值一定是指针
    struct tag *pnext;
}tag_t, *ptag_t;


void InitQueue(LinkQueue& Q);
bool QueueEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, ElemType x);
ElemType DeQueue(LinkQueue &Q);
void PrintQueue(LinkQueue Q);



#endif //FUNCTION_H
