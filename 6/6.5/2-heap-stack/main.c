#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * print_stack() {
    char buf[100] = "I am print_stack func";
    puts(buf);
    return buf;
}

char * print_malloc() {
    // 堆空间
    char *buf = (char *)malloc(100); // 堆空间在整个进程中一直有效，不因为函数结束而释放
    strcpy(buf, "I am print_malloc func");
    puts(buf);
    return buf; // 未释放内存
}

// 堆和栈的差异
int main(void) {

    char *p;
    p = print_stack(); // 输出的是乱码。因为返回的是地址，而函数执行完后，内存会被释放掉
    puts(p);
    p = print_malloc();
    puts(p); // 输出的是正常的字符串
    free(p); // 只有free的时候才会释放内存
    // puts(p); // 输出的是乱码，因为已经释放了内存
    return 0;
}
