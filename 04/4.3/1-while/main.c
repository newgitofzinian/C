#include <stdio.h>

// 使用while求和1-100
int main(void) {
    int i=1, total = 0;
    while (i <= 100) {
        total += i;
        i++;
    }
    // 注意，while后不能加分号，不然会死循环 while(); 编译会通过
    printf("total=%d\n", total);
    return 0;
}
