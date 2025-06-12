#include <iostream>

// C++ 引用案例实战
// 例子2: 这种情况要不要添加引用?

typedef struct student {
    int num;
    float score;
}stu;

void change(stu *p)
{
    p->num = 2002;
    p->score = 85.0;
}

int main() {
    stu *p = (stu *)malloc(sizeof(stu));
    p->num = 2001;
    p->score = 90.5;
    std::cout << "Before change: num = " << p->num << ", score = " << p->score << std::endl;
    change(p);
    std::cout << "After change: num = " << p->num << ", score = " << p->score << std::endl;
    free(p);
    // short si = -32767;
    // unsigned short usi = si;
    // printf("short si = %d, usi = %u\n", si, usi);
    return 0;
}

// 个人认为不需要,因为空间一直存在.
// 正确确实不需要引用