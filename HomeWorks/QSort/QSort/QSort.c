#include <stdio.h>
#include "library.h"


int main(void) {

    int Array[10] = { 8, 7, 3, 9, 1, 0, -5, 7, 2, 2 };

    insertionSort(Array, 10);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", Array[i]);
    }
}