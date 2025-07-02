#include <stdio.h>

int main(void) {
    int i , j = 1;
    while(scanf("%d", &i)) {
        if (i%4 == 0 && i%100 != 0 || i%400 == 0) {
            printf("%d is leap year\n", i);
        }
        else {
            printf("%d is not leap year\n", i);
        }
    }
    i = !! j;
    printf("i value is %d", i);
    return 0;
}