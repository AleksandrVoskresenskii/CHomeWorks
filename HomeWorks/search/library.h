#include <stdio.h>
#include <stdlib.h>

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

int medium(int a, int b, int c) {
    return a + b + c - max(max(a, b), c) - min(min(a, b), c);
}


void qSort(int* Array, int lenArray) {

    if (lenArray <= 10) {
        insertionSort(&Array[0], lenArray);
        return;
    }

    int mediumAraay = 0;
    mediumAraay = medium(Array[0], Array[lenArray / 2], Array[lenArray - 1]);
    int cutArray = 0;
    int left = 0, right = lenArray - 1;

    while (left != right) {
        if (Array[left] < mediumAraay) {
            ++left;
            cutArray = left;
            continue;
        }
        if (Array[right] >= mediumAraay) {
            --right;
            continue;
        }
        swap(&Array[left], &Array[right]);
    }

    if (cutArray == 0 || cutArray == lenArray - 1) {
        insertionSort(&Array[0], lenArray);
        return;
    }

    qSort(Array, cutArray);
    qSort(&Array[cutArray], lenArray - cutArray);
    return;
}

int binSearch(int* Array, int lenArray, int key) {
    int left = 0;
    int right = lenArray - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (Array[middle] == key) {
            return middle;
        }

        if (Array[middle] < key) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}