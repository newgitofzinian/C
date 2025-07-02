
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
2. 堆排序

**归并类排序**分为
1. 归并排序
2. 快速排序

## 排序算法比较
| 排序算法    | 平均时间复杂度       | 最好情况          | 最坏情况     | 空间复杂度       | 稳定性 |
|---------|---------------|---------------|----------|-------------|-----|
| 冒泡排序    | O($n^2$)      | O($n$)        | O($n^2$) | O($1$)      | 稳定  |
| 快速排序    | O($nlog_2 n$) | O($nlog_2 n$) | O($n^2$) | O($log_2n$) | 不稳定 |
| 直接插入排序  | O($n^2$)      | O($n$)        | O($n^2$) | O($1$)      | 稳定  |
| 折半插入排序  | O($n^2$)      | O($nlog_2 n$) | O($n^2$) | O($1$)      | 稳定  |

| 希尔排序    | O(n^1.3)      | O(n)          | O(n^2)   | O(1)        | 不稳定 |
| 简单选择排序  | O(n^2)        | O(1)          | 不稳定      | O(1)        | 稳定  |
| 堆排序     | O(nlogn)      | O(nlogn)      | O(nlogn) | O(1)        | 不稳定 |



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
