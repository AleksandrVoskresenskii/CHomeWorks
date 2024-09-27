#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void bubbleSort(int* Array, int lenArray) {
    int counSwap = 0;
    for (int i = 0; i < lenArray; ++i) {
        counSwap = 0;
        for (int j = lenArray - 1; j >= i; --j) {
            if (Array[j] < Array[j - 1]) {
                swap(&Array[j], &Array[j - 1]);
                counSwap++;
            }
        }
        if (counSwap == 0) {
            break;
        }
    }
}


void countingSort(int* Array, int lenArray) {
    int maxInArray = Array[0], minInArray = Array[0];
    for (int i = 0; i < lenArray; ++i) {
        maxInArray = max(Array[i], maxInArray);
        minInArray = min(Array[i], minInArray);
    }
    int lenNewArray = maxInArray - minInArray;


    int* NewArray;
    int n = lenNewArray + 1;

    NewArray = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        NewArray[i] = 0;
    }


    for (int i = 0; i < lenArray; ++i) {
        NewArray[Array[i] - minInArray] += 1;
    }

    int stopperInArray = 0, counterStopInArray = 0;

    for (int i = 0; i <= maxInArray - minInArray; ++i) {
        stopperInArray = counterStopInArray;
        for (int j = stopperInArray; j < stopperInArray + NewArray[i]; ++j) {
            Array[j] = i + minInArray;
            counterStopInArray++;
        }
    }

    free(NewArray);
}


bool test1() {
    int A[3] = { 3, 1, 2 }, IdA[3] = { 1, 2, 3 };
    bubbleSort(&A, 3);
    if (A[0] == IdA[0] && A[1] == IdA[1] && A[2] == IdA[2]) {
        return 1;
    }
    return 0;
}

bool test2() {
    int A[3] = { 3, 1, 2 }, IdA[3] = { 1, 2, 3 };
    countingSort(&A, 3);
    if (A[0] == IdA[0] && A[1] == IdA[1] && A[2] == IdA[2]) {
        return 1;
    }
    return 0;
}

bool test() {
    return test1() * test2();
}

int main(void) {
    if (!test()) {
        return 1;
    }
    //int Array[12] = { 10, 25, 62, 826, 1, 2983, -3, 3 , 92, 31, -500, 23874};
    //int arrayLen = sizeof(Array) / sizeof(Array[0]);

    int* Array;
    int arrayLen = 100000;

    Array = (int*)malloc(arrayLen * sizeof(int));
    for (int i = 0; i < arrayLen; i++) {
        Array[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", Array[i]);
    }


    countingSort(Array, arrayLen);

    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", Array[i]);
    }

    printf("\n%ld", clock());

    free(Array);
}