#include <stdio.h>

// 指针的使用场景——传递与偏移
// 传递

// 在子函数去改变主函数中某个变量的值
void change1(int j) {
    // 函数调用是值传递，传递的是副本，不会影响到原变量的值
    j = 5;
}

void change2(int *j) {
    // 函数调用是地址传递，传递的是指针，可以改变原变量的值，拿到的是变量i的空间
    *j = 5;
}

int main(void) {
    int i = 10;
    printf("before change, i = %d\n", i);
    change1(i); // 调用函数时，实参i的值传递给形参j
    printf("after change1, i = %d\n", i);
    change2(&i);
    printf("after change2, i = %d\n", i);
    return 0;
}