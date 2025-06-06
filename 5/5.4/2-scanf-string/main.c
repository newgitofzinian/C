#include <stdio.h>


// scanf读取字符串操作，会自动往字符数组中放结束符
int main(void) {
    char s[10], c[10];

    /** 读取整数时，需要取地址符号，即:
    * int i;
    * scanf("%d", &i);
    * 而字符串不需要地址符则是因为 字符数组名str中，存储了数组的起始地址吗*/

    // scanf("%s", s);
    // 不能读取空格，读取到空格，scanf会默认读取完毕，输入缓冲区内其他数据就会被忽略
    // printf("%s", s);

    // 连续输入两个字符
    scanf("%s%s", s, c);
    printf("%s\t%s\n", s, c);

    return 0;
}