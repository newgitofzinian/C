#include <stdio.h>

// 数组传递给子函数
void change(char *d) { // 数组名作为实参传递给子函数时，是弱化为指针的
    *d = 'H';
    d[1] = 'E';
    *(d+2) = 'L';
}



int main(void) {

    char c[10] = "hello";
    change(c);
    puts(c);
    return 0;
}