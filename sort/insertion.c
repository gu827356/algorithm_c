//
// Created by hcx on 2020/7/4.
//

#include "sort.h"

void insertion_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j, j - 1);
            }
        }
    }
}