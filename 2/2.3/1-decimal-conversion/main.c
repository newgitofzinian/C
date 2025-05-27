#include <stdio.h>
// 整数类型转换
int main(void) {
    int i = 123;
    i = 0x7b; // 十进制
    i = 0173; // 八进制
    printf("i = %d\n", i);  // 十进制
    printf("i = %o\n", i);  // 二进制
    printf("i = %x\n", i);  // 十六进制
}