#include <iostream>
typedef int ElemType;

// 双链表栈
typedef struct DbSNode {
    ElemType data;
    DbSNode *last, *next;
}DbSNode, *LDbS;

void InitStack(LDbS &S) {
    S = nullptr;
}

bool StackEmpty(LDbS S) {
    return S==nullptr;
}
// 入栈
bool Push(LDbS &S, ElemType x) {
    LDbS p = new DbSNode;
    p->data = x;
    p->next = nullptr;
    if (StackEmpty(S)) {
        p->last = nullptr;
    }else {
        p->last = S;
        S->next = p;
    }
    S = p;
}
// 出栈
bool Pop(LDbS &S, ElemType &x) {
    if (StackEmpty(S)) {
        return false;
    }
    x = S->data;
    LDbS p = S;
    if (S->last != nullptr) {
        S = p->last;
        S->next = nullptr;
    }else {
        S = nullptr;
    }

    delete p;
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
