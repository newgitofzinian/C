# 考研必会的排序算法

排序算法氛围交换类排序,插入排序,选择排序,归并类排序

**交换排序**:

1. 冒泡排序 (一般考选择题,大题概率低)
2. 快速排序(非常重要,大题概率高)

**插入排序**:   (都只考选择题,考大题概率低)

1. 插入排序
2. 折半插入排序
3. 希尔排序

**选择排序**分为

1. 简单选择排序
2. 堆排序 (重点)

**归并类排序**分为

1. 归并排序
2. 快速排序

## 排序算法比较

算法的稳定性: 若排序表有两个元素R1和R2,两元素的关键字值相等,且R1在R2前面,而R2在R1后面.排序后,若R1和R2的相对位置不变,则称该排序算法是稳定的.


| 排序算法         | 平均时间复杂度  | 最好情况        | 最坏情况       | 空间复杂度    | 稳定性 | 复杂性 |
| ---------------- | --------------- | --------------- | -------------- | ------------- | ------ | ------ |
| **冒泡排序**     | O($n^2$)        | O($n$)          | O($n^2$)       | O($1$)        | 稳定   | 简单   |
| **快速排序**     | O($nlog_2 n$)   | O($nlog_2 n$)   | O($n^2$)       | O($log_2n$)   | 不稳定 | 较复杂 |
| **直接插入排序** | O($n^2$)        | O($n$)          | O($n^2$)       | O($1$)        | 稳定   | 简单   |
| **简单选择排序** | O($n^2$)        | O($n^2$)        | O($n^2$)       | O($1$)        | 不稳定 | 简单   |
| **堆排序**       | O($nlog_2n$)    | O($nlog_2n$)    | O($nlog_2n$)   | O(1)          | 不稳定 | 较复杂 |
| **归并排序**     | O($nlog_2n$)    | O($nlog_2n$)    | O($nlog_2n$)   | O($n$)        | 稳定   | 较复杂 |
| ---------        | --------------- | --------------- | -------------- | ------------- | -----  | -----  |
| 希尔排序         | O($n^1.3$)      |                 |                | O($1$)        | 不稳定 | 较复杂 |
| 折半插入排序     | O($n^2$)        | O($nlog_2 n$)   | O($n^2$)       | O($1$)        | 稳定   |        |
| 基数排序         | O($d(n+r)$)     | O($d(n+r)$)     | O($d(n+r)$)    | O($r$)        | 稳定   | 较复杂 |

## 冒泡排序

### 基本思想

从前往后(或者从后往前),两两比较,根据从小到大或者从大到小,去选择是否交换位置.每次排序都把最小元素(或最大元素)放在序列最终位置,这样,最多`n-1`趟把所有元素排好序.

```c++
void bubble_sort(ElemType str[], int len, int id) {
    bool flag;
    if (id == 1) {
        for (int i = 0; i < len - 1; i++) {
            flag = false;
            for (int j = 0; j < len - 1 - i; j++) {
                if (str[j] > str[j + 1]) {
                    swap(str[j], str[j + 1]);
                    flag = true;
                }
            }
            if (!flag) {    // 若没有发生交换，则说明已经有序，则退出循环
                break;
            }
        }
    } else if (id == 0) {
        for (int i = 0; i < len - 1; i++) {
            flag = false;
            for (int j = 0; j < len -1 -i; j++) {
                if (str[j] < str[j + 1]) {
                    swap(str[j], str[j + 1]);
                    flag = true;
                }
            }
            if (!flag) { // 若没有发生交换，则说明已经有序，则退出循环
                break;
            }
        }
    }
    return;
}
```

## 快速排序 (非常重要‼️)

### 基本思想

(分治思想):假设我们的目标是从小到大的顺序排列,我们找到数组中的一个分割值,把比分割值小的放在左边(反之放右边),比分割值大的放在右边,这样数组一分为二,污蔑只需要排前一半数组和后一半数组.采用这种思想,不断进行递归,最终分割只剩一个元素时,整个序列自然有序.

```c++
ElemType Partittion(ElemType arr[], int low, int high) {    // 一趟划分
    ElemType pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] < pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quick_sort(ElemType arr[], int low, int high) {
    if (low < high) {   // 递归条件
        ElemType pivot = Partittion(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
    return;

}
```

## 插入排序

也叫直接插入排序,是一种简单排序算法

### 基本思想

如果一个序列只有一个数,那么该序列自然有序.插入排序首先把第一个数视为有序序列,然后从第二个数开始,将其插入到有序序列中,依次类推,直到所有数都插入完成.

```C++
// 代码不重要
void insert_sort(ElemType arr[], int len) {
    for (int i = 1; i < len; i++) {
        ElemType key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}  
```

## 简单选择排序

### 基本思想

假设排序表`L[1...n]`,第`i`趟排序即从`L[1...i]`中选择关键字最小的元素与`L[i]`交换,每一趟排序可以确定一个元素的最终位置.
这样经过`n-1`趟排序,整个序列就有序.

```c++
void select_sort(ElemType arr[], int len){
    for(int i = 0; i < len - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < len, j++){
            if ( arr[min_idx] > arr[j]){
                min_idx = j
            }
        }
        if ( min_idx != i){
            swap(arr[min_idx], arr[i])
        }
    }
}
```

## 堆排序

### 基本思想

堆排序是一种树形选择排序,它是利用堆数据结构的特点来实现的.堆是一个完全二叉树,其中每个节点的值都大于或等于其左右孩子节点的值(大根堆).堆排序(升序)的基本思想是:将待排序的序列构造成一个堆,然后从堆的顶端开始,依次将堆中最大的元素与堆的最后一个元素交换,然后再调整堆,使其继续满足堆的性质,直到堆的大小为1,此时整个序列有序.

```c++
void HeapAdjust(ElemType arr[], int start, int len) {  // 时间复杂度0(h) h = log2(n)
    int root = start;
    int child;
    for (child = 2 * root + 1; child < len; child = 2 * child + 1) {
        // 找出root节点的左右孩子中较大的
        if (child + 1 < len && arr[child] < arr[child + 1]) {
            child++;
        }
        // 如果root节点的左右孩子中较大的不是root节点，则交换root节点和较大的孩子节点
        if (arr[child] > arr[root]) {
            swap(arr[root], arr[child]);
            root = child; // 继续调整子树, 新的root节点是child节点, 继续比较
        } else {
            break;
        }
    }
}


void BuildMaxHeap(ElemType arr[], int len) {    // 时间复杂度0(n)
    for (int i = len / 2 - 1; i >= 0; i--) {
        // 从最后一个非叶子节点开始 调整为最大堆
        HeapAdjust(arr, i, len); // 调整以i为根节点的子树为最大堆
    }
}


void heap_sort(ElemType arr[], int len) {  // 时间复杂度 O(nlog2n)
    // 建堆
    BuildMaxHeap(arr, len);
    // 堆排序
    for (int i = len - 1; i > 0; i--) {
        // 交换堆顶元素和最后一个元素
        swap(arr[0], arr[i]);
        // 调整堆
        HeapAdjust(arr, 0, i);
    }
}
```

## 归并排序

### 基本思想

归并排序的代码采用递归思想实现.归并的含义是将两个或更多有序序列合并成一个有序序列.归并排序的基本思想是:先递归地将两个子序列合并成一个有序序列,然后再合并两个有序序列,直到所有子序列都有序.

Merge()函数的作用是将两个有序序列合并成一个有序序列.
考研默认两两归并

```c++
void Merge(ElemType arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    ElemType temp[MAXN];
    while (i <= mid && j <= right) {


```
