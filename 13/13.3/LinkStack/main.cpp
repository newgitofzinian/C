#include <iostream>
typedef int ElemType;
// 单链式存储的栈
typedef struct Stack {
    ElemType data;
    Stack *next;
}LStack, *LinkStack;

void InitStack(LinkStack &S) {
    S = NULL;   // 不带头结点
}

bool  StackEmpty(LinkStack S) {
    return S==NULL;
}

// 入栈
bool Push(LinkStack &S, ElemType x) {
    LinkStack p = new LStack();
    p->data = x;
    // if (StackEmpty(S)) {
    //     S = p;
    // }
    p->next = S;
    S = p;
    return true;
}


// 出栈
bool Pop(LinkStack &S, ElemType &x) {
    if (StackEmpty(S))
        return false;
    LinkStack p = S;
    x = p->data;
    S = p->next;
    delete p;
    return true;
}

int main() {
    // 测试
    LinkStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    ElemType x;
    Pop(S, x);
    std::cout << x << std::endl;
    Pop(S, x);
    std::cout << x << std::endl;
    Pop(S, x);
    std::cout << x << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}