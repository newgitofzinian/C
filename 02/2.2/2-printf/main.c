#include <stdio.h>


// printf 具体代码格式
/**
 * %c 字符
 * %d 整数
 * %f 浮点型
 * %s 一串字符
 */
int main(void) {
    int i = 1001;
    float f = 96.3;
    printf("student number=%d,score=%f\n",i,f);
    printf("student number=%d,score=%5.2f\n",i,f);// %5.2f显示5个字符，2个小数点位
    i = 10;
    printf("student number=%3d,score=%5.2f\n",i,f); // %3d显示3个字符
    printf("student number=%-3d,score=%5.2f\n",i,f);// 加符号左对齐，不加右对齐

}