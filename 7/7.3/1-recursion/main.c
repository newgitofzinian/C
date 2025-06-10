#include "func.h"
// 函数的递归调用


int main(void) {
    int n;
    scanf("请输入一个数计算阶乘: %d", &n);
    printf("f(%d) = %d\n", n, f(n));
    // printf("Hello, World!\n");
    return 0;
}