#include <stdio.h>
#include <stdbool.h>
#include "library.h"



int main(void) {

    int n = 100, k = 10;

    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    int* ArrayN;
    int arrayNLen = n;

    ArrayN = (int*)malloc(arrayNLen * sizeof(int));
    for (int i = 0; i < arrayNLen; i++) {
        ArrayN[i] = rand() % 1000;
    }

    int* ArrayK;
    int arrayKLen = k;

    ArrayK = (int*)malloc(arrayKLen * sizeof(int));
    for (int i = 0; i < arrayKLen; i++) {
        ArrayK[i] = rand() % 1000;
    }

    qSort(ArrayN, arrayNLen);

    for (int i = 0; i < arrayKLen; ++i) {
        printf("%d ", binSearch(ArrayN, arrayNLen, ArrayK[i]));
    }


    return 0;
}