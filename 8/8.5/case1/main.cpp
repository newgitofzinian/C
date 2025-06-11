#include <iostream>

// C++ 引用案例实战
// 例子1: 通过子函数修改主函数的结构体变量是否可以?

typedef struct student {
    int num;
    float score;
}stu;

void change(stu s) // 不能改变结构体变量
// void change2(stu& s) // 通过引用修改结构体变量
{
    s.num = 2002;
    s.score = 85.0;
}




int main() {
    stu s = {1001, 90.5};
    std::cout << "num: " << s.num << ", score: " << s.score << std::endl;
    change(s);
    // change2(s);
    std::cout << "num: " << s.num << ", score: " << s.score << std::endl;
    return 0;
}