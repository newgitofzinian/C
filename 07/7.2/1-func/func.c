//
// Created by 子年 on 25-6-9.
//

#include "func.h"

int print_star(int n) {
    printf("**********************\n");
    printf("print_star %d\n", n);
    return n+3;
}

// 函数的定义放在func.h中，函数的实现放在func.c中
// 可以调用prin_star函数，也可以调用print_message函数
void print_message() {
    printf("how do you do?\n");
    print_star(6);
}