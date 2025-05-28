#include <stdio.h>
// sizeof() 实际上是一个运算符，而非函数
  // 用于求常量或变量所占空间的大小
int main(void) {
    int i = 0;
    printf("i size is %d\n",sizeof(i));
    return 0;
}