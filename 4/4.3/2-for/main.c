#include <stdio.h>

// for循环实现1加到100
int main(void) {
    int total = 0;
    for (int i = 1; i <= 100; i++) {    // 同样不能加分号
        total += i;
    }
    printf("total = %d\n", total);
    return 0;
}
