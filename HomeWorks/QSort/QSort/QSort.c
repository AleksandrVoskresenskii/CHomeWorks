#include <stdio.h>
#include <stdlib.h>
#include "library.h"


int main(void) {

    //int Array[10] = { 8, 7, 3, 9, 1, 0, -5, 7, 2, 2 };

    //insertionSort(&Array[1], 9);

    /*int Array[100] = { 0 }, len = 100;
    for (int i = 0; i < len; ++i) {
        Array[i] = rand() % 100;
    }*/

    /*for (int i = 0; i < len; ++i) {
        printf("%d ", Array[i]);
    }*/
    
    printf("\n");

    int* Array;
    int arrayLen = 300000;

    Array = (int*)malloc(arrayLen * sizeof(int));
    for (int i = 0; i < arrayLen; i++) {
        Array[i] = rand() % 1000;
    }


    qSort(Array, arrayLen);

    for (int i = 0; i < arrayLen - 1; ++i) {
        if (Array[i] > Array[i + 1]) {
            printf("Error");
        }
        //printf("%d ", Array[i]);
        
    }
    printf("%d", (1 / 2) + 1);
    free(Array);
}