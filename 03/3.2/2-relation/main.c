#include <stdio.h>

/* C语言没有bool类型的值，所以用0来代替假，1代替真
 * 例如
 * 5>2 为1
 * 5<2 为0
 * 关系运算符优先级小于算术运算符
 */
int main(void) {
    int i;
    while (scanf("%d", &i)) {
        if (i > 3 && i < 10) { // 3 < a < 10 会出现错误，因为先运算 3<a,结果为0或1，0或1小于10，所以永远为真
            printf("a is between 3 and 10\n");
        }
        else {
            printf("a is not between 3 and 10\n");
        }
    }
    return 0;
}
