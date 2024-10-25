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

int modaArray(int* A, int lenArray) {
    int localMax = 1;
    int globalMax = 0;
    int maxIndex = 0;

    qSort(A, lenArray);

    for (int i = 1; i < lenArray; ++i) {
        if (A[i] == A[i - 1]) {
            localMax += 1;
        }
        else {
            localMax = 1;
        }
        if (localMax > globalMax) {
            globalMax = localMax;
            maxIndex = i;
        }
    }

    return A[maxIndex];
}