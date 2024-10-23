#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

void printBin(unsigned char number) {
    unsigned char mask = 128;

    for (int i = 0; i < 8; ++i) {
        printf("%c", (number & mask) ? '1' : '0');
        mask >>= 1;
    }
}

void calculatorBin(unsigned char number1, unsigned char number2, bool *resultSum) {
    unsigned char mask = 1;
    int bit1 = 0, bit2 = 0, carry = 0, sumBit = 0;

    for (int i = 8; i >= 1; --i) {
        bit1 = (number1 & mask) ? 1 : 0;
        bit2 = (number2 & mask) ? 1 : 0;
        sumBit = bit1 + bit2 + carry;

        if (sumBit == 2 || sumBit == 3) {
            carry = 1;
        }
        else {
            carry = 0;
        }
        resultSum[i] = sumBit % 2;
        mask <<= 1;
    }
    resultSum[0] = carry;
    bool ifZeroFlag = true;
    for (int i = 1; i < 9; ++i) {
        if (resultSum[i]) {
            ifZeroFlag = false;
        }
    }
    if (ifZeroFlag) {
        resultSum[0] = 0;
    }

}

int binaryToDecimal(bool* binNumber) {
    int decNumber = binNumber[0] ? -256 : 0;
    int degree = 128;
    for (int i = 1; i < 9; ++i) {
        decNumber += binNumber[i] * degree;
        degree >>= 1;
    }
    return decNumber;
}

bool test1(unsigned char number1, unsigned char number2, int result) {
    bool resultSum[9] = { false };

    calculatorBin(number1, number2, &resultSum);
    return (binaryToDecimal(&resultSum) == result);

}


bool test(void) {
    return test1(65, 64, 129) && test1(-65, -64, -129) && test1(65, -65, 0);
}





int main() {
    setlocale(LC_ALL, "Rus");

    if (!test()) {
        return 1;
    }


    unsigned char number1, number2;
    bool resultSum[9] = { false };

    printf("Введите первое слагаемое (до 127): ");
    scanf("%hhu", &number1);
    printf("Введите второе слагаемое (до 127): ");
    scanf("%hhu", &number2);

    printf("\nПервое число в двоичном формате: ");
    printBin(number1);
    printf("\nВторое число в двоичном формате: ");
    printBin(number2);

    printf("\nСумма в двоичном формате: ");
    calculatorBin(number1, number2, &resultSum);
    for (int i = 0; i < 9; ++i) {
        printf("%c", (resultSum[i]) ? '1' : '0');
    }
    printf("\nСумма в десятичном формате: %d", binaryToDecimal(&resultSum));

    printf("\n");
    return 0;
}
