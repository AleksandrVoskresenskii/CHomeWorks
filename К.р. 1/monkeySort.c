#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool isSorted(int Array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (Array[i] > Array[i + 1]) {
            return false;
        }
    }
    return true;
}


void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}


void shuffle(int Array[], int lenArray) {
    for (int i = 0; i < lenArray; i++) {
        int j = rand() % lenArray;
        swap(&Array[i], &Array[j]);
    }
}


void monkeySort(int Array[], int lenArray) {
    while (!isSorted(Array, lenArray)) {
        shuffle(Array, lenArray);
    }
}

bool test1() {
    int Array[] = { 1, 2, 3, 4, 5 };
    int len = sizeof(Array) / sizeof(Array[0]);
    monkeySort(Array, len);
    return isSorted(Array, len);
}

bool test2() {
    int Array[] = { 5, 4, 3, 2, 1 };
    int len = sizeof(Array) / sizeof(Array[0]);
    monkeySort(Array, len);
    return isSorted(Array, len);
}

bool test3() {
    int Array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int len = sizeof(Array) / sizeof(Array[0]);
    monkeySort(Array, len);
    return isSorted(Array, len);
}

bool test4() {
    int Array[] = {};
    int len = 0;
    monkeySort(Array, len);
    return isSorted(Array, len);
}


bool test5() {
    int Array[] = { 52 };
    int lenArray = sizeof(Array) / sizeof(Array[0]);
    monkeySort(Array, lenArray);
    return isSorted(Array, lenArray);
}


bool test(void) {
    return test1() && test2() && test3() && test4() && test5();
}


int main() {
    if (!test()) {
        printf("Error");
        return 0;
    }
    int Array[] = { 3, 1, 4, 1, 5, 9 };
    int lenArray = sizeof(Array) / sizeof(Array[0]);

    monkeySort(Array, lenArray);

    printf("Sorted array:\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}