#include <stdio.h>

// scanf 一次性读多种数据类型
int main(void) {
    int i, ret;
    float f;
    char c;
    ret = scanf("%d %f %c", &i, &f, &c); // ret是匹配成功的个数 不加空格会出错
    printf("i = %d, c= %c, f=%5.2f", i, c, f);
    return 0;
}