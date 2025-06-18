#include <iostream>
// 尾插法新建链表

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode* next;
}LNode, *LinkList;
// 尾插法
LinkList LinkTailInsert(LinkList &L) {
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 头结点
    // L = new LNode; // 头结点
    LNode *s, *r = L; // r为表尾指针
    scanf("%d", &x);
    while (x!=-1) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;  // r指向新的尾结点
        scanf("%d", &x);
    }
    r->next = nullptr;
    return L;
}
// 打印链表
void PrintLinkList(LinkList L) {
    LNode *p = L->next;
    while (p!= nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
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
int main() {
    LinkList L = nullptr;
    L = LinkTailInsert(L);
    PrintLinkList(L);
    DeleteLinkList(L);
    return 0;

}