#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void poluQSort(int* Array, int lenArray) {
    int point = Array[0];
    int counterStart = 0, counterEnd = lenArray - 1;

    while (counterEnd > counterStart) {
        if (Array[counterStart] < point) {
            ++counterStart;
        }
        else if (Array[counterEnd] >= point) {
            --counterEnd;
        }
        else {
            swap(&Array[counterEnd], &Array[counterStart]);
        }
    }

}

bool test1(void) {
    int A[5] = { 3, 1, 5, 5, 2 }, len = 5, B[5] = { 2, 1, 5, 5, 3 };
    poluQSort(A, len);
    return A[0] == B[0] && A[1] == B[1] && A[2] == B[2] && A[3] == B[3] && A[4] == B[4];
}

int main(void) {
    if (!test1()) {
        printf("Error!");
        return 0;
    }
    int Array[30] = { 0 }, len = 30;
    for (int i = 0; i < 30; ++i) {
        Array[i] = rand();
    }
    printf("%d\n", Array[0]);
    poluQSort(Array, len);
    for (int i = 0; i < 30; ++i) {
        printf("%d ", Array[i]);
    }
}