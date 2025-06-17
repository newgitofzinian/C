//
// Created by 子年 on 25-6-13.
//

#ifndef DYNAMIC_SEQ_LIST_H
#define DYNAMIC_SEQ_LIST_H
#include <iostream>
#include <stdio.h>
#define InitSize 100
#define MaxSize 50

typedef int ElemType; // 设置元素类型
typedef struct {
    ElemType *data;
    size_t capacity; // size_t 无符号整型 最大容量
    size_t length;  // 当前个数
} DynamicSeqList;

// 初始化动态顺序表
void InitList(DynamicSeqList &list);

// 插入元素到顺序表,默认尾部
bool ListInsert(DynamicSeqList &list, ElemType element, size_t pos);

// 删除指定位置到元素
bool ListDelete(DynamicSeqList &list, size_t pos);

// 打印顺序表的内容
void ListPrint(const DynamicSeqList &list);


#endif //DYNAMIC_SEQ_LIST_H
