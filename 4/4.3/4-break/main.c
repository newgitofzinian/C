#include <stdio.h>

// Break直接退出循环
int main(void) {
    int i, total=0;
    for (i = 1; i <= 100; i++) {    // 同样不能加分号
        if (i % 2 == 0) {
            continue;   // continue后面的代码都不会得到执行
        }
        total += i;
        if (total > 2000) {
            break; // 当和大于2000时，就退出循环
        }

    }
    printf("total = %d，i = %d\n", total, i);
    return 0;
}
