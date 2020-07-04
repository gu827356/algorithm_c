//
// Created by hcx on 2020/7/3.
//

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

struct TestCase {
    char *name;
    int *arr;
    int size;
};

typedef struct TestCase TestCase;

const int test_case_count = 3;
TestCase *test_cases;

void init_test_case() {
    test_cases = calloc(test_case_count, sizeof(TestCase));
    test_cases[0].name = "0 长度";
    test_cases[0].size = 0;

    test_cases[1].name = "1 长度";
    test_cases[1].size = 1;
    test_cases[1].arr = calloc(1, sizeof(int));
    test_cases[1].arr[0] = 10;

    TestCase *tc = test_cases + 2;
    tc->name = "10 长度";
    tc->size = 10;
    tc->arr = calloc(10, sizeof(int));
    tc->arr[0] = 92;
    tc->arr[1] = 10;
    tc->arr[2] = 91;
    tc->arr[3] = 1;
    tc->arr[4] = 892;
    tc->arr[5] = 10;
    tc->arr[6] = 93;
    tc->arr[7] = 9102;
    tc->arr[8] = 0;
    tc->arr[9] = 29;
}

typedef void (*SortAlgorithm)(int *, int);

int *alloc_int_arr(int size) {
    if (size < 1) {
        return NULL;
    }
    int *ret = calloc(size, sizeof(int));
    return ret;
}

void copy(void *dist, void *src, size_t size) {
    char *d = dist;
    char *s = src;
    for (int i = 0; i < size; ++i) {
        *(d + i) = *(s + i);
    }
}

int valid_sort(int const *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void run_test(char *name, SortAlgorithm algorithm) {
    printf("run %s\n", name);
    for (int i = 0; i < test_case_count; ++i) {
        TestCase *tc = &test_cases[i];
        int size = tc->size;

        printf("(%s): ", tc->name);

        int *arr = alloc_int_arr(size);
        copy(arr, tc->arr, size);

        algorithm(arr, size);

        if (valid_sort(arr, size)) {
            printf("success");
        } else {
            printf("fail");
        }
        printf("\n");

        free(arr);
    }
    printf("\n");
}


int main() {
    printf("sort ......\n");
    init_test_case();

    run_test("选择排序", selection_sort);

    run_test("插入排序", insertion_sort);

    run_test("冒泡排序", bubble_sort);

    return 0;
}