#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C语言的数组长度固定是因为定义的整型、浮点型、字符型变量、数组变量都在栈空间中，
// 而指针变量则在堆空间中，所以指针变量的长度是不固定的，需要用malloc函数动态分配内存。
// 使用空间大小不确定，那么需要使用堆空间
int main(void) {
    int space_size;// 要申请的空间大小
    char *p; // 指针变量

    printf("请输入要申请的空间大小：");
    scanf("%d", &space_size);

    // 申请空间
    p = (char *)malloc(space_size); // p的大小永远是8字节，32位则是4字节
    // void *malloc(size_t size);需要给malloc传递到参数是一个整形变量
    // 这里的size_t是系统定义的类型，用来表示内存大小，在32位系统上，size_t的大小为4字节，
    // 在64位系统上，size_t的大小为8字节。
    // 在这里的size_t即为int；返回值为 void *类型，即指向申请到的内存的指针。
    // void * 类型智能存储一个地址而不能进行偏移，这里我们需要强制转换为char *类型，
    // 因为后面要用字符串操作函数。
    strcpy(p, "malloc successful!"); // 用strcpy函数将字符串拷贝到申请到的内存中
    puts(p); // 用puts函数打印申请到的内存
    // 释放申请到的内存
    free(p); // 释放申请到的内存, free 必须使用malloc申请时返回的指针值，不能进行偏移
    printf("释放内存成功！\n");



    return 0;
}