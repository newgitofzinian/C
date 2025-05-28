#include <stdio.h>

// 短路运算
// 逻辑与和逻辑或
int main(void) {
    int i = 0;
    i&&printf("you can't see me\n");
    // 等价于
    if (i) {
        printf("you can't see me\n");
    }
    // 当i为假时不会运行逻辑与后的表达式，称之为短路运算

    int j = 1;
    j||printf("you can't see me\n");
    // 当j为真时，不会运行逻辑或后的表达式，称之为短路运算

    return 0;
}