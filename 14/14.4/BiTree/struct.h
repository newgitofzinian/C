//
// Created by 子年 on 25-6-23.
// 存放结构体  自己写的

#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>
typedef int (*fun)(int, int);
typedef char BiElemType;
typedef struct BiNode {
    BiElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
void LevelOrder(BiTree T);
void visit(BiNode *p);

typedef struct QNode {
    char data;
    struct QNode *next;
} QNode, *Queue;
typedef struct {
    Queue front, rear;
} LinkQueue, *LinkQueuePtr;
void initQueue(Queue *q);bool isEmpty(Queue q);
void enQueue(Queue *q, char x);
void deQueue(Queue *q, char *x);
void DestroyQueue(Queue *q);
// 默认层次建树,但是可以根据参数来进行不用序列建树
BiTree CreateBiTree(int pre[], char *in, int n);

typedef struct tag {
    BiTree p;   // 树的某一个结点的地址值
    struct tag *pnext;
}tag_t, *ptag_t;


#endif //STRUCT_H
