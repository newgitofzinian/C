#include <stdio.h>

// void 这个地方是函数返回值的类型
// 当不需要返回时，写void
// 需要整数返回值，就写int; 浮点型，就写folat
// 数组名传递到子函数后，子函数的形参接受的是数组的起始地址，因此，不能直接传递数组的长度。
void print(int a[], int n) {
    int i;
    // for (i = 0; i < sizeof(a)/sizeof(int); i++) {
    for (i = 0; i < n; i++){
        printf("%3d", a[i]);
    }
    a[3] =  20; // 里面可以修改
    printf("\n");
}



// 数组传递
// main函数就是子函数
int main(void) {
    int a[6] = {1, 2, 3, 4, 5, 6};
    // print(a, 5); // 1, 2
    print(a, sizeof(a)/sizeof(int));
    printf("%d", a[3]);
    return 0;
}