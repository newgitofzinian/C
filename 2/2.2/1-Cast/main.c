#include <stdio.h>
// 强制类型转换
int main(void) {
    int i = 5;
    float f = i /2; // 左右操作数都为整数、所以这里为整数运行
    // 强制类型转换
    float k = (float)i / 2 ;
    printf("%f\n", f); // 2
    printf("%f\n", k); // 2.5
    return 0;
}