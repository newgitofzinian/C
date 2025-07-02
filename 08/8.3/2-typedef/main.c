#include <stdio.h>


// 使用typedef声明新的类型名代替已有的类型名

// 结构体指针
typedef struct student {
    int num;
    char name[20];
    char sex;
}stu, *pstu;
// typedef struct student stu;
// stu等价于 struct student;
// pstu等价于 struct student *;
int main(void) {
    stu s={0};
    stu *p=&s;
    pstu p1=&s; // pstu等价于 struct student *;
    return 0;
}