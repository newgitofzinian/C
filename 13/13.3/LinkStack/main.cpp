#include <iostream>
typedef int ElemType;
// 单链式存储的栈
typedef struct Stack {
    ElemType data;
    Stack *next;
}LStack, *LinkStack;

void InitStack(LinkStack S) {
    S = NULL;   // 不带头结点
}

bool  StackEmpty(LinkStack S) {
    return S==NULL;
}

// 入栈
bool Push(LinkStack S, ElemType x) {
    LinkStack p = new LStack();
    p->data = x;
    p->next = S;
    S = p;
    return true;
}


// 出栈
bool Pop(LinkStack S, ElemType &x) {
    if (StackEmpty(S))
        return false;
    LinkStack p = S;
    x = p->data;
    S = p->next;
    delete p;
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}