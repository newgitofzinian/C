//
// Created by 子年 on 25-6-19.
//

#ifndef LISTFUNC_H
#define LISTFUNC_H
#include <iostream>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode* next;
}LNode, *LinkList;

bool InitList(LinkList& L);
bool IsEmpty(LinkList L);
LinkList LinkTailInsert(LinkList& L, int x); // x是自动生成的test,自动生成x个
LinkList LinkHeadInsert(LinkList& L);
void LinkListPrint(LinkList L);
LinkList GenerateRandomLinkList(int n=10);
std::pair<LinkList, int> LocateElem(LinkList L, ElemType x);
LinkList GetElem(LinkList L, size_t SearchPos);
void DeleteLinkList(LinkList& L);


#endif //LISTFUNC_H
