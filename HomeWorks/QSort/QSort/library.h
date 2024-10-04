#include <stdio.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}


void insertionSort(int* Array, int lenArray) {
    for (int i = 1; i < lenArray; ++i) {
        for (int j = i; j > 0; --j) {
            if (Array[j] >= Array[j - 1]) {
                break;
            }
            swap(&Array[j], &Array[j - 1]);
        }
    }
}