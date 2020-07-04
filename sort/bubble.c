//
// Created by hcx on 2020/7/4.
//

#include "sort.h"

// 冒泡排序通过每一次外层循环保证最大的元素被移动到了末尾。
// 冒泡排序和选择排序刚还相反。
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}