//
// Created by hcx on 2020/7/3.
//

#include "sort.h"
#include <stdio.h>

void print_int_arr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if(i != size - 1) printf(", ");
    }
    printf("]\n");
}

void swap(int *arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}