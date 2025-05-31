#include <stdio.h>

// 两层for循环
int main(void) {
    int i, j;
    for (i = 0; i < 5; i++) {
        printf("外层循环i=%d\n",i);
        for (j = 0; j < 5; j++) {
            printf("内层循环j=%d ",j);
        }
        printf("\n");
    }
    return 0;
}