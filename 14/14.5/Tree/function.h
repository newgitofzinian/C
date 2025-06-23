//
// Created by 子年 on 25-6-23.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

typedef char  BiElemType;
typedef struct BiTNode {
    BiElemType data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// tag 结构体是辅助队列使用
typedef struct tag {
    BiTree addr;   // 存的值一定是指针
    struct tag *pnext;
}tag_t, *ptag_t;

#endif //FUNCTION_H
