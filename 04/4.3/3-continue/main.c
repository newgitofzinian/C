#include <stdio.h>

// 使用continue，求奇数和
int main(void) {
    int i, total=0;
    for (int i = 1; i <= 100; i++) {    // 同样不能加分号
        if (i % 2 == 0) {
            continue;   // continue后面的代码都不会得到执行
        }
        total += i;
    }
    printf("total = %d\n", total);
    return 0;
}
