#include <stdio.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void reverseArray(int* Array, int m, int n) {

    int lenArray = n + m;
    
    int rightM = m - 1, leftM = 0;

    for (int i = 0; i < m / 2; ++i) {
        swap(&Array[leftM], &Array[rightM]);
        ++leftM;
        --rightM;
    }

    int rightN = lenArray - 1, leftN = m;

    for (int i = 0; i < n / 2; ++i) {
        swap(&Array[leftN], &Array[rightN]);
        ++leftN;
        --rightN;
    }

    int right = lenArray - 1, left = 0;

    for (int i = 0; i < lenArray / 2; ++i) {
        swap(&Array[left], &Array[right]);
        ++left;
        --right;
    }
}


int main(void) {

    int ArrayTest[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    int m = 10, n = 5;

    reverseArray(ArrayTest, 10, 5);

    for (int i = 0; i < m + n; ++i) {
        printf("%d ", ArrayTest[i]);
    }



    return 0;
}