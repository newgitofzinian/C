#include <stdio.h>

struct score{
    int math;
    int english;
    int chinese;
};


struct student {
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    // struct score scores;
}; // 结构体类型声明，最后一定要加分号
    

int main(void) {
    struct student s = {0, "Tom", 'M', 18, 80.9}; // 结构体变量声明
    struct student sarr[3]; // 结构体数组声明
    int i;

    s.num=1003;
    printf("%d %s %c %d %f\n", s.num, s.name, s.sex, s.age, s.score); // %c 输出单个字符
    printf("--------------------\n");
    scanf("%d %s %c %d %f\n", &s.num, &s.name, &s.sex, &s.age, &s.score);
    printf("--------------------\n");
    printf("%d %s %c %d %f\n", s.num, s.name, s.sex, s.age, s.score);
    sarr[i] = s;
    return 0;
}