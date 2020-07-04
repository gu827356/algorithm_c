//
// Created by hcx on 2020/7/3.
//

#include "sort.h"

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = min_index + 1; j < size; ++j) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        swap(arr, min_index, i);
    }
}