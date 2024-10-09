#include <stdio.h>
#include <stdbool.h>

bool palindrome(char* inputString, int lenStr) {

    int left = 0, right = lenStr - 1;

    for (int i = 0; i < lenStr; ++i) {
        if (inputString[left] == ' ') {
            ++left;
            continue;
        }
        if (inputString[right] == ' ') {
            --right;
            continue;
        }
        if (right <= left) {
            return true;
        }
        if (inputString[left] != inputString[right]) {
            return false;
        }
        --right;
        ++left;
    }
    return true;
}

bool test1(void) {
    char inputString[19] = "€ иду с мечем суди€";
    return palindrome(inputString, 19);
}

bool test2(void) {
    char inputString[19] = "я     g      я     ";
    return palindrome(inputString, 19);
}

bool test3(void) {
    char inputString[2] = "€€";
    return palindrome(inputString, 2);
}

bool test4(void) {
    char inputString[19] = "€ иуу с мцчем суди€";
    return !palindrome(inputString, 19);
}

bool test(void) {
    return test1() && test2() && test3() && test4();
}