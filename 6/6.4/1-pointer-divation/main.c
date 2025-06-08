#include <stdio.h>
# define N 5

// 指针的偏移使用场景
int main(void) {
    int arr[N] = {1, 2, 3, 4, 5};
    int *p; // 定义指针变量
    p = arr; // 指针指向数组首元素
    int i;
    for (i = 0; i < N; i++) {
        printf("%3d", *(p + i)); //p是int型指针，*(p+i)是int型变量，所以p+1地址上加4
        // printf("%3d\n", arr[i]);
    }
    printf("\n-----------\n");
    p = &arr[4];
    printf("%3d\n", *p);


    return 0;
}
