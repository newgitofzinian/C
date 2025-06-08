#include <stdio.h>

// 指针
int main(void) {
    int i = 5; //定义整型变量i
    char c = 'a'; // 定义字符型变量c
    // 定义整型指针变量i_pointer，并初始化
    int *i_pointer = &i;
    // 定义字符型指针变量c_pointer；
    char *c_pointer;
    // 变量c的地址赋值给c_pointer;
    c_pointer = &c;
    // 指针分不同类型是因为取值可以拿到的空间大小不同
    // *i_pointer 可以拿到4个字节大小空间
    // *c_pointer 可以拿到1个字节大小空间

    printf("i的地址为%p\n", (void*)i_pointer);
    printf("c的地址为%p\n", (void*)c_pointer);
    //1. 使用了 `%p` 格式化符号来打印指针（即变量的地址）。
    //2. 将指针类型转换为 `void*` 是为了符合 `%p` 的标准要求，因为 `%p` 需要一个 (void*) 类型的参数。

    return 0;
}
