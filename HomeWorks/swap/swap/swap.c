#include <stdio.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

int main(void) {
    int a = 25, b = 50;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}