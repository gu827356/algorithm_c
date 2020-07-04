//
// Created by hcx on 2020/6/2.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct Heap {
    int *arr;
    int size;
    int cap;
} Heap;

Heap *allocHeap(int cap) {
    Heap *h = malloc(sizeof(Heap));
    h->size = 0;
    h->cap = cap;

    
    return h;
}

void freeHeap(Heap *h) {
    free(h);
}

int heapParent(int i) {
    return (i - 1) / 2;
}

int heapLeft(int i) {
    return (i << 1) + 1;
}

int heapRight(int i) {
    return (i + 1) << 1;
}

void printHeap(Heap *h) {
    printf("Heap{size=%d, cap=%d}\n", h->size, h->cap);
}

void testPos(int i) {
    printf("pos(%d): {parent=%d, left=%d, right=%d}\n",
            i, heapParent(i), heapLeft(i), heapRight(i));
}

void main() {
    Heap *h = allocHeap(10);
    printHeap(h);

    freeHeap(h);

    for (int i = 0; i < 10; ++i) {
        testPos(i);
    }
}