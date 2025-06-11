#include <stdio.h>

struct student_type1 {
    double score; // 8
    int height; // 4
    short age; // 2
    // 大小是最大成员的整数倍
    // 要确保对齐
};

struct student_type2 {
    int height; //4
    char sex;  // 1
    short age; //2
};



int main(void) {
    struct student_type1 student1 = {4,5,6};
    struct student_type2 student2 = {7,8,9};
    printf("student1 size = %d\n", sizeof(student1)); // 16字节
    printf("student2 size = %d\n", sizeof(student2)); // 8 字节
    return 0;
}