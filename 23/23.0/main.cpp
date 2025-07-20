#include <cstring>
#include <stdio.h>
#include <stdlib.h>


// C语言创建无结构文件
// int main1() {
//     // 创建流式文件
//     // FILE *fp = fopen("test.txt", "w"); // 打开文件
//     // if (fp == NULL) {
//     //     printf("文件打开失败！\n");
//     //     exit(0);
//     // }
//     //
//     // // 写入一个hello world
//     // for (int i = 0; i < 10000; i++) {
//     //     fputs("hello world\n", fp); // 写入字符串
//     // }
//     // fclose(fp); // 关闭文件
//
//     // 读取流式文件
//     // FILE *fp = fopen("test.txt", "r");
//     // if (fp == NULL) {
//     //     printf("Fail to open file!");
//     //     exit(0);
//     // }
//     //
//     // fseek(fp, 16, SEEK_SET);    // 读写指针指向16
//     // char c = fgetc(fp);     // 从读写指针读取1个字符
//     // printf("字符: %c", c);
//     // fclose(fp);
//     return 0;
// }

// C 语言创建顺序文件
typedef struct {
    int number; // 学号
    char name[30];  // 姓名
    char major[30];    // 专业
}Student_info;
#define N 10
int main() {
    //
    // // 以写的方式打开文件
    // FILE *fp = fopen("students.info", "w");
    // if (fp == NULL) {
    //     printf("打开文件失败!");
    //     exit(0);
    // }
    //
    // Student_info student[N];    //  用数组保存N个学生信息
    // for (int i = 0; i < N; ++i) {
    //     student[i].number = i;
    //     // strcpy(student[i].name, "张三");
    //     student[i].name[0] = '?';
    //     // student[i].major[0] = '?';
    //     strcpy(student[i].major, "化学");
    // }
    //
    // // 将N个学生信息写入文件
    // fwrite(student, sizeof(Student_info), N, fp);
    // fclose(fp);

    // 以读的方式打开文件
    FILE *fp = fopen("students.info", "r");
    if (fp == NULL) {
        printf("打开文件失败!");
        exit(0);
    }

    // 文件读写指针指向编号为5的学生信息
    fseek(fp, 5 * sizeof(Student_info), SEEK_SET);
    Student_info student;
    fread(&student, sizeof(Student_info), 1, fp);
    printf("学号: %d\n", student.number);
    printf("姓名: %s\n", student.name);
    printf("专业: %s\n", student.major);
    fclose(fp);

    return 0;
}

