#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体指针
struct student {
    int num;
    char name[20];
    char sex;
};
// typedef struct student stu;

// 结构体指针的练习
int main(void) {
    struct student s={1000,"wanglei", 'M'};
    struct student sarr[3] = {1001,"lilei",'M', 1002,"zhangsan",'M',1003,"lisi",'F'};
    struct student *p;  // 定义一个结构体指针变量
    p = &s;
    printf("%d %s %c\n", s.num, (*p).name, p->sex); // 三种访问方式
    p = sarr;
    printf("%d %s %c\n", p->num, p->name, p->sex);
    p = p+1; // 访问数组下一个成员
    printf("%d %s %c\n", p->num, p->name, p->sex);

    // 下面给结构体指针p通过malloc申请空间，并对其成员赋值，再访问
    p = (struct student*)malloc(sizeof(struct student)); // 申请一个结构体空间
    p->num = 1004;
    p->sex = 'F';
    strcpy(p->name, "longge"); // 给字符串赋值需要用strcpy，而非前面两种
    printf("%d %s %c\n", p->num, p->name, p->sex);

    return 0;
}