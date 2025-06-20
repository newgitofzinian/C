#include <iostream>
#define Maxsize 50
typedef int Elemtype;
typedef struct{
    Elemtype data[Maxsize];
    int top;
}SqStack;

// s.top = -1; 栈为空
void InitStack(SqStack &S) {
    S.top = -1;
}
bool StackEmpty(SqStack S) {
    return S.top == -1;
}
// 入栈操作
bool Push(SqStack &S, Elemtype x) {
    if (S.top == Maxsize - 1) {
        std::cout << "栈满！" << std::endl;
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    // S.data[++S.top] = x; 等价于上一行
    return true;
}
// 出栈操作
bool Pop(SqStack &S, Elemtype &x) {
    if (StackEmpty(S)) {
        std::cout << "栈空！" << std::endl;
        return false;
    }
    x = S.data[S.top--];
    // S.top--;
    // x = S.data[S.top]; 等价于上一行
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, Elemtype &x) {
    if (StackEmpty(S)) {
        std::cout << "栈空！" << std::endl;
        return false;
    }
    x = S.data[S.top];
    return true;
}

// 栈的应用
void PrintStack(SqStack S) {
    Elemtype x;
    while (!StackEmpty(S)) {
        Pop(S, x);
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    PrintStack(S);
    std::cout << "栈顶元素：" << S.data[S.top] << std::endl;
    Elemtype x;
    GetTop(S, x);
    std::cout << "栈顶元素：" << x << std::endl;
    Pop(S, x);
    std::cout << "出栈元素：" << x << std::endl;
    // 打印栈是否为空
    if (StackEmpty(S)) {
        std::cout << "栈为空！" << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}