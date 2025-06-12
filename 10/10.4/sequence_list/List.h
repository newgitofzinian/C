//
// Created by 子年 on 25-6-12.
//

#ifndef LIST_H
#define LIST_H
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
// 动态分配 了解即可,不考察
#define InitSize 100
typedef struct {
    ElemType *data; //指向第一个数据的指针
    int capacity; // 动态数组的最大容量
    int length; // 当前个数
}SeqList;

// 静态分配 重点!!!!
typedef struct {
    ElemType data[MaxSize];
    int length; // 当前顺序表有多少个元素
}SqList;

bool ListInsert(SqList &L, int pos, ElemType element);
void PrintList(SqList L);
bool ListDelete(SqList &L, ElemType &del, int pos = 1); // 默认pos为1
int LocateElem(SqList L, int pos);


#endif //LIST_H
