#include "library.h"


int main(void) {
    if (!test()) {
        return 1;
    }
    char inputString[19] = "� ��� � ����� �����";
    if (palindrome(inputString, 19)) {
        printf("True");
    }
    else {
        printf("False");
    }
}