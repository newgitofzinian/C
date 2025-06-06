#include <stdio.h>


// 数组访问越界
int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int j = 20;
    int i = 10;
    printf("a[0]=%d\n", arr[0]);
    arr[5] = 6; //访问越界
    arr[6] = 7;
    printf("%d", i);// i
    // for (int k = 1; k < i; k++) {
    //     printf("a[%d]=%d\n", k, arr[k]);  // 访问越界
    // }
    return 0;
}