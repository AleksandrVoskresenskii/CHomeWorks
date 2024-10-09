#include <stdio.h>
#include <stdbool.h>
#include "library.h"



//bool binSearch(int* Array, int lenArray, int number) {
//    qSort(Array, lenArray);
//
//    int cutterLen = lenArray / 4 + 1;
//    int carriage = lenArray / 2 + 1;
//    bool isHaveInArray = false;
//
//    while (cutterLen > 1 && carriage >= 0 && carriage < lenArray) {
//        if (Array[carriage] > number) {
//            
//        }
//    }
//
//
//}


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