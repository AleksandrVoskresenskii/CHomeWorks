#include "library.h"
#include <locale.h>

#define MAX_LEN 1000

#define FILENAME "array.txt"


int main(void) {
    setlocale(LC_ALL, "Rus");
    int count = 0;
    int Array[MAX_LEN];


    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Файл \"array.txt\" не найден.\n");
        return 1;
    }

    while (count < MAX_LEN && fscanf(file, "%d", &Array[count]) == 1) {
        count++;
    }

    fclose(file);

    fclose(file);
    int arrayLen = count;

    printf("Moda in Array: %d", modaArray(&Array, arrayLen));
}